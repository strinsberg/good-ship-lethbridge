#include "EntityConnector.h"
#include "Suit.h"
#include "Container.h"
#include "Room.h"
#include "Npc.h"
#include "Player.h"
#include "json.h"

using json = nlohmann::json;

EntityConnector::EntityConnector(
    json obj, std::map<std::string, Entity*>& ents, std::map<std::string, Event*>& evts)
    : object(obj), entities(ents), events(evts) {}

EntityConnector::~EntityConnector() {}

void EntityConnector::visit(Entity* e) {
    connectEvents(e);
}

void EntityConnector::visit(Suit* s) {
    connectEvents(s);
}

void EntityConnector::visit(Container* c) {
    connectEvents(c);
    connectItems(c);
}

void EntityConnector::visit(Room* c) {
    connectEvents(c);
    connectItems(c);
}

void EntityConnector::visit(Npc* c) {
    connectEvents(c);
    connectItems(c);
}

void EntityConnector::visit(Player* c) {
    connectEvents(c);
    connectItems(c);
}

// Private /////////////////////////////////////////////////////////////////////

void EntityConnector::connectEvents(Entity* e) {
    for (auto event : object["events"]) {
        std::string id = event["id"];
        if (events.find(id) != events.end())
            e->addEvent(event["verb"], events[id]);

    }
}

void EntityConnector::connectItems(Container* c) {
    for (auto entity : object["items"]) {
        std::string id = entity["id"];
        if (entities.find(id) != entities.end())
            c->addEntity(entities[id]);
    }
}
