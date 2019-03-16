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
std::string Container::use(Entity*) {
  return "you can't use containers";
}
ObjectBlueprint* Container:: makeBlueprint() const {
  ObjectWithContentsBlueprint* bp = static_cast<ObjectWithContentsBlueprint*>
                                    (Entity::makeBlueprint());
  bp->setField("type", "container");

  // for loop to add all items with this container as owner to the blueprint
  for (auto iPair : inventory) {
    ObjectBlueprint* ebp = iPair.second->makeBlueprint();
    ebp->setField("owner", spec->getName());
    bp->addBlueprint(ebp);
  }

  return bp;
}

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

Entity* Container::findOwner(std::string name) {
  auto it = inventory.find(Game::toLower(name));
  if (it == inventory.end()) {
    for (auto itemPair : inventory) {
      if (Container* c = dynamic_cast<Container*>(itemPair.second)) {
        Entity* e = c->search(Game::toLower(name));
        if (e!= nullptr)
          return c;
      }
    }
    return nullptr;
  } else {
    return this;
  }
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
