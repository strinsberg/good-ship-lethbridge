/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-23
 */

#include "Container.h"
#include "Entity.h"
#include "Game.h"  // eventually move toLower to a library
#include "Npc.h"
#include <utility>
#include <string>
#include <sstream>
#include <map>


Container::Container(std::string id)
    : Entity(id), inventory(std::map<std::string, Entity*>()) {}

Container::~Container() {
  for (auto e : inventory) {
    delete e.second;
  }
}

std::string Container::describe() const {
  std::stringstream ss;
  // Give container description
  ss << spec->getDescription();
  if (inventory.size() > 0)
    ss << "\n";

  // Add descriptions for all contained entities at the top level only
  size_t i = 0;
  for (auto e : inventory) {
    ss << e.second->getSpec()->getName() << " -> ";
    ss << e.second->getSpec()->getDescription();
    if (i < inventory.size() - 1)
      ss << "\n";
    i++;
  }
  return ss.str();
}

Entity* Container::search(std::string name) const {
  for (auto entry : inventory) {
    // If this is the object you want return it
    if (entry.second->matches(Game::toLower(name))) {
      return entry.second;
    // If the object is not what you want and it is a container search it
    } else if (Container* con = dynamic_cast<Container*>(entry.second)) {
      if (Npc* n = dynamic_cast<Npc*>(con)) {
        // Can't see items in Npcs
        continue;
      } else {
        Entity* e = con->search(Game::toLower(name));
        // If you find the entity return it
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
