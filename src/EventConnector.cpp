#include "EventConnector.h"
#include "Connector.h"
#include "Event.h"
#include "Inform.h"
#include "ToggleActive.h"
#include "TransferItem.h"
#include "EventGroup.h"
#include "ConditionalEvent.h"
#include "json.h"

using json = nlohmann::json;

EventConnector::EventConnector(
        json obj, std::map<std::string, Event*> evts, std::map<std::string, Conditional*> conds, std::map<std::string, Entity*> ents)
        : object(obj), events(evts), conditions(conds), entities(ents) {}

EventConnector::~EventConnector() {}

void EventConnector::visit(Inform* i) {
    connectSubjects(i);
}

void EventConnector::visit(ToggleActive* t) {
    connectSubjects(t);
    std::string targetId = object["target"];
    if (entities.find(targetId) != entities.end())
        t->setTarget(entities[targetId]);
}

void EventConnector::visit(TransferItem* t) {
    connectSubjects(t);
    std::string otherId = object["target"];
    if (entities.find(otherId) != entities.end())
        t->setOther(static_cast<Container*>(entities[otherId]));
}

void EventConnector::visit(EventGroup* g) {
    connectSubjects(g);
    for (auto event : object["events"]) {
        std::string id = event["id"];
        if (events.find(id) != events.end()) {
            g->addEvent(events[id]);
        }
    }
}

void EventConnector::visit(ConditionalEvent* c) {
    connectSubjects(c);
    std::string condId = object["condition"];
    std::string succId = object["success"];
    std::string failId = object["failure"];
    //Test with if's or assert not nullptr in setters
    c->setCondition(conditions[condId]);
    c->setSuccess(events[succId]);
    c->setFailure(events[failId]);
}

void EventConnector::visit(Interaction* i) {
    connectSubjects(i);
    for (auto event : object["events"]) {
        std::string id = event["id"];
        if (events.find(id) != events.end()) {
            std::string optionText = object["name"];
            i->addOption(optionText, events[id]);
        }
    }
}

void EventConnector::connectSubjects(Event* e) {
    for (auto subject : object["subjects"]) {
        std::string id = subject["id"];
        if (events.find(id) != events.end())
            events[id]->subscribe(e);
    }
}
