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

std::string Container::describe() const {
  std::stringstream ss;

  ss << spec->getDescription();
  if (inventory.size() > 0)
    ss << "\n";

  size_t i = 0;
  for (auto e : inventory) {
    ss << e.second->getSpec()->getName() << " -> " << e.second->getSpec()->getDescription();
    if (i < inventory.size() - 1)
      ss << "\n";
    i++;
  }
  return ss.str();
}

Entity* Container::search(std::string name) const {
  for (auto entry : inventory) {
    if (entry.second->matches(Game::toLower(name))) {
      return entry.second;
    } else if (Container* con = dynamic_cast<Container*>(entry.second)) {
      if (Npc* n = dynamic_cast<Npc*>(con)) {
        continue;
      } else {
        Entity* e = con->search(Game::toLower(name));
        if (e != nullptr)
          return e;
      }
    }
  }
  return nullptr;
}

Entity* Container::searchById(std::string id) {
  std::pair<Container*, Entity*> entityPair = findEntity(id);
  if (entityPair.first != nullptr) {
    return entityPair.second;
  } else {
    return nullptr;
  }
}

void Container::addEntity(Entity* entity) {
  inventory[ Game::toLower(entity->getSpec()->getId()) ] = entity;
}

void Container::removeEntity(Entity* entity) {
  inventory.erase(Game::toLower(entity->getSpec()->getId()));
}

Entity* Container::searchAndRemove(std::string id) {
  std::pair<Container*, Entity*> entityPair = findEntity(id);
  if (entityPair.first != nullptr) {
    entityPair.first->removeEntity(entityPair.second);
    return entityPair.second;
  } else {
    return nullptr;
  }
}

std::map<std::string, Entity*>::iterator Container::begin() {
  return inventory.begin();
}
std::map<std::string, Entity*>::iterator Container::end() {
  return inventory.end();
}

// Private ///////////////////////////////////////////////////////////

std::pair<Container*, Entity*> Container::findEntity(std::string id) {
  std::string ID = Game::toLower(id);
  auto it = inventory.find(ID);

  // If the item is not in this container search any containers it contains
  if (it == inventory.end()) {
    for (auto entry : inventory) {
      if (Container* con = dynamic_cast<Container*>(entry.second)) {
        if (Npc* n = dynamic_cast<Npc*>(con)) { // Skip Npcs
          continue;
        } else {
          std::pair<Container*, Entity*> entityPair = con->findEntity(ID);
          if (entityPair.first != nullptr)
            return entityPair;
        }
      }
    }
    // No item with given id exists
    return std::pair<Container*, Entity*>(nullptr, nullptr);
  } else {
    // The item is in the top-level container
    return std::pair<Container*, Entity*>(this, it->second);
  }
}
