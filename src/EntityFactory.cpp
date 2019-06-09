#include "EntityFactory.h"
#include "Entity.h"
#include "Container.h"
#include "Npc.h"
#include "Room.h"
#include "json.h"

using json = nlohmann::json;


EntityFactory::EntityFactory() {}

EntityFactory::~EntityFactory() {}

Entity* EntityFactory::makeEntity(const json& obj) {
    Entity* e = new Entity(obj["id"]);
    setupEntity(e, obj);
    return e;
}

Container* EntityFactory::makeContainer(const json& obj) {
    std::string type = obj["type"];
    std::string id = obj["id"];
    Container* c;

    if (type == "container")
        c = new Container(obj["id"]);
    else if (type == "room")
        c = new Room(id);
    else if (type == "npc")
        c = new Npc(id);

    setupEntity(c, obj);
    return c;
}

Player* EntityFactory::makePlayer(const json& obj) {
    Player* p = new Player(obj["id"]);
    setupEntity(p, obj);
    return p;
}

void EntityFactory::setupEntity(Entity* e, const json& obj) {
    EntitySpec* spec = e->getSpec();
    spec->setId(obj["id"]);
    spec->setName(obj["name"]);
    spec->setDescription(obj["description"]);
    EntityState* state = e->getState();
    state->setActive(obj["active"] == 1);
    state->setObtainable(obj["obtainable"] == 1);
    state->setHidden(obj["hidden"] == 1);
}
