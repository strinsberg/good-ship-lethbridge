#include "EntityConnector.h"
#include "Container.h"
#include "json.h"
#include <iostream>

using json = nlohmann::json;

EntityConnector::EntityConnector(
        json obj, std::map<std::string, Entity*>& ents, std::map<std::string, Event*>& evts)
        : object(obj), entities(ents), events(evts) {}

EntityConnector::~EntityConnector() {}

void EntityConnector::visit(Entity* e) {
    connectEvents(e);
}

void EntityConnector::visit(Container* c) {
    connectEvents(c);
    for (auto entity : object["items"]) {
        std::string id = entity["id"];
        if (entities.find(id) != entities.end())
            c->addEntity(entities[id]);
            std::cout << id << entity["name"] << std::endl;
    }
}

void EntityConnector::connectEvents(Entity* e) {
    for (auto event : object["events"]) {
        std::string id = event["id"];
        if (events.find(id) != events.end())
            e->addEvent(event["verb"], events[id]);

    }
}
