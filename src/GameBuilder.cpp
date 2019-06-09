/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11, 2019-04-20, 2019-06-8
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Room.h"
#include "Door.h"
#include "Npc.h"
#include "Inform.h"
#include "Kill.h"
#include "MovePlayer.h"
#include "ToggleActive.h"
#include "TransferItem.h"
#include "EventGroup.h"
#include "StructuredEvents.h"
#include "Interaction.h"
#include "ConditionalEvent.h"
#include "HasItem.h"
#include "Question.h"
#include "Protected.h"
#include "Event.h"
#include "Entity.h"
#include "ObjectBlueprint.h"
#include "GameData.h"
#include "Exceptions.h"
#include "EntityConnector.h"
#include "EventConnector.h"
#include "json.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

using json = nlohmann::json;


GameBuilder::GameBuilder() {}

GameBuilder::~GameBuilder() {}

Game* GameBuilder::newGame(std::string name) {
  // Create a game
  Game* g = new Game();
  std::vector<ObjectBlueprint*> blueprints;

  // NEW create all objects
  std::map<std::string, Entity*> entities;
  std::map<std::string, Event*> events;
  std::map<std::string, Conditional*> conditions;

  std::ifstream in("test.world");  // Error Checking???
  json worldBlueprint;
  in >> worldBlueprint;


  for (auto& obj : worldBlueprint["objects"]) {
    std::string type = obj["type"];
    std::string id = obj["id"];

    if (isEntity(type)) {
        entities[id] = makeEntity(obj);
    } else if (isEvent(type)) {
        events[id] = makeEvent(obj);
    } else if (isCondition(type)) {
        conditions[id] = makeCondition(obj);
    }
  }

  // NEW connect all objects
  // if an object has events find them and add them
  // if an object has items find them and add them
  for (auto& obj : worldBlueprint) {
    std::string type = obj["type"];
    std::string id = obj["id"];

    if (isEntity(type)) {
        Entity* e = entities[id];
        EntityConnector conn(obj);
        conn.collect(entities, events);
        e->accept(conn);
    } else if (isEvent(type)) {
        Event* e = events[id];
        EventConnector conn(obj);
        conn.collect(events, conditions);
        e->accept(conn);
    } else if (type == "player") {
        Player* p = new Player(id);
        setupEntity(p, obj);
        EntityConnector conn(obj);
        conn.collect(entities, events);
        p->accept(conn);
        g->setPlayer(p);
    }
  }

  // Add everything to the game
  g->setEntities(entities);
  g->setEvents(events);
  g->setConditions(conditions);

  g->setName(worldBlueprint["name"]);
  g->setWelcome(worldBlueprint["welcome"]);
  g->setVersion(worldBlueprint["version"]);

  // Return the game
  return g;
}

// Private ///////////////////////////////////////////////////////////////////

bool GameBuilder::isEntity(std::string type) {
    return type == "entity" || type == "container" || type == "room"
        || type == "npc";
}
bool GameBuilder::isEvent(std::string type) {
    return type == "inform" || type == "kill" || type == "toggle"
        || type == "transfer" || type == "move" || type == "group"
        || type == "ordered" || type == "interaction" || type == "conditional";
}

bool GameBuilder::isCondition(std::string type) {
    return type == "hasItem" || type == "question" || type == "protected";
}

Entity* GameBuilder::makeEntity(json obj) {
    std::string id = obj["id"];
    std::string type = obj["type"];

    Entity* e;
    if (type == "container")
        e = new Container(id);
    else if (type == "room")
        e = new Room(id);
    else if (type == "suit")
        e = new Suit(id, obj["atmosphere"]);
    else
        e = new Entity(id);

    setupEntity(e, obj);
    return e;
}

void GameBuilder::setupEntity(Entity* e, json obj) {
    e->getSpec()->setName(obj["name"]);
    e->getSpec()->setDescription(obj["description"]);
    e->getState()->setActive(obj["active"] == 1);
    e->getState()->setObtainable(obj["obtainable"] == 1);
    e->getState()->setHidden(obj["hidden"] == 1);
}

Event* GameBuilder::makeEvent(json obj) {
    std::string id = obj["id"];
    std::string type = obj["type"];

    Event* e;
    if (type == "inform")
        e = new Inform(id, obj["message"]);
    else if (type == "kill")
        e = new Kill(id, obj["message"], obj["ending"] == 1);
    else if (type == "toggle")
        e = new ToggleActive(id);
    else if (type == "transfer")
        e = new TransferItem(id, obj["item"], obj["toTarget"] == 1);
    else if (type == "move")
        e = new MovePlayer(id);
    else if (type == "group")
        e = new EventGroup(id);
    else if (type == "ordered")
        e = new StructuredEvents(id);
    else if (type == "interaction")
        e = new Interaction(id);
    else if (type == "conditional")
        e = new ConditionalEvent(id);

    e->setOnce(obj["once"]);

    return e;
}

Conditional* GameBuilder::makeCondition(json obj) {
    std::string id = obj["id"];
    std::string type = obj["type"];

    Conditional* c;
    if (type == "hasItem")
        c = new HasItem(id, obj["item"]);
    else if (type == "question")
        c = new Question(id, obj["question"], obj["answer"]);
    else if (type == "protected")
        c = new Protected(id, obj["atmosphere"]);

    return c;
}
