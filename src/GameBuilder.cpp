/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11, 2019-04-20, 2019-06-8
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Room.h"
#include "Door.h"
#include "Npc.h"
#include "EventGroup.h"
#include "Event.h"
#include "Entity.h"
#include "ObjectBlueprint.h"
#include "GameData.h"
#include "Exceptions.h"
#include "EventFactory.h"
#include "EntityFactory.h"
#include "ConditionFactory.h"
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
  std::map<std::string, Container*> containers;
  std::map<std::string, Event*> events;
  std::map<std::string, EventGroup*> groups;
  std::map<std::string, Conditional*> conditions;

  std::ifstream in("test.world");  // Error Checking???
  json worldBlueprint;
  in >> worldBlueprint;

  // Make some factory objects
  // Use then to create the objects needed
  EntityFactory entFact;
  EventFactory evtFact;
  ConditionFactory condFact;

  for (auto& obj : worldBlueprint["objects"]) {
    std::string type = obj["type"];
    std::string id = obj["id"];

    if (isEntity(type)) {
        if (isContainer(type))
            containers["id"] = entFact.makeContainer(obj);
        else
            entities[id] = entFact.makeEntity(obj);
    } else if (isEvent(type)) {
        if (isGroup(type))
            groups[id] = evtFact.makeGroup(obj);
        else
            events[id] = evtFact.makeEvent(obj);
    } else if (isCondition(type)) {
        conditions[id] = condFact.make(obj);
    }
  }

  // NEW connect all objects
  // if an object has events find them and add them
  // if an object has items find them and add them
  for (auto& obj : worldBlueprint) {
    std::string type = obj["type"];
    std::string id = obj["id"];

    if (isContainer(type)) {
        Container* c = containers[id];
        addItems(c, obj["items"]);
        addEvents(c, obj["events"]);
    } else if (isEntity(type)) {
        Entity* e = entities[id];
        addEvents(e, obj["events"]);
    } else if (isGroup(type)) {
        EventGroup* g = groups[id];
        addEvents(g, obj["events"]);
        setSubscriptions(g, obj["subjects"]);
    } else if (isEvent(type)) {
        Event* e = events[id];
        setSubscriptions(e, obj["subjects"]);
    }
  }

  // Add everything to the game


  // Return the game
  return g;
}

// Private ///////////////////////////////////////////////////////////////////

bool GameBuilder::isEntity(std::string type) {
    return false;
}
bool GameBuilder::isEvent(std::string type) {
    return false;
}

bool GameBuilder::isContainer(std::string type) {
    return false;
}

bool GameBuilder::isGroup(std::string type) {
    return false;
}

bool GameBuilder::isCondition(std::string type) {
    return false;
}

void GameBuilder::addItems(Container* c, json items) {

}

void GameBuilder::addEvents(Entity* e, json events) {

}

void GameBuilder::addEvents(EventGroup* g, json events) {

}

void GameBuilder::setSubscriptions(Event* e, json subjects) {

}
