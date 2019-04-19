/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Container.h"
#include "Entity.h"
#include "Game.h"
#include "ObjectWithContentsBlueprint.h"
#include "Npc.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>

Container::Container() : inventory(std::map<std::string, Entity*>()) {}

Container::~Container() {
  for (auto e : inventory) {
    delete e.second;
  }
}

std::string Container::describe()const {
  std::stringstream ss;
  if (inventory.size() > 0) {
    ss << std::endl << "Contains: "<< std::endl;
  }
  for (auto e : inventory) {
    ss << e.first << std::endl;
  }
  ss.str();
  return  spec->getDescription() + ss.str();
}


// Needs to change so that name is searched for with iteration
// as things will be stored by id soon
Entity* Container::search(std::string name) const {
  auto it = inventory.find(Game::toLower(name));
  if (it == inventory.end()) {
    for (auto itemPair : inventory) {
      if (Container* c = dynamic_cast<Container*>(itemPair.second)) {
        if (Npc* n = dynamic_cast<Npc*>(c)) {
          continue;
        } else {
          Entity* e = c->search(Game::toLower(name));
          if (e!= nullptr)
            return e;
        }
      }
    }
    return nullptr;
  } else {
    return it->second;}
}

Entity* Container::searchById(std::string id) const {
  auto it = inventory.find(Game::toLower(id));
  if (it == inventory.end()) {
    for (auto itemPair : inventory) {
      if (Container* c = dynamic_cast<Container*>(itemPair.second)) {
        if (Npc* n = dynamic_cast<Npc*>(c)) {
          continue;
        } else {
          Entity* e = c->search(Game::toLower(id));
          if (e!= nullptr)
            return e;
        }
      }
    }
    return nullptr;
  } else {
    return it->second;}
}

void Container::addEntity(Entity* entity) {
  inventory[ Game::toLower(entity->getSpec()->getName()) ] = entity;
}

void Container::removeEntity(Entity* entity) {
  inventory.erase(Game::toLower(entity->getSpec()->getName()));
}

std::map<std::string, Entity*>::iterator Container::begin() {
  return inventory.begin();
}
std::map<std::string, Entity*>::iterator Container::end() {
  return inventory.end();
}
