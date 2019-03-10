#include "Container.h"
#include "Entity.h"


Container::Container():inventory(std::map<std::string, Entity*>()) {}

Container::~Container() {
  for (auto e: inventory) {
    delete e.second;
  }
}

std::string Container::describe()const {
  return spec->getDescription();
}
std::string Container::use(Entity*) {
  return "you can't use containers";
}
ObjectBlueprint* Container:: makeBlueprint() const {}

Entity* Container::search(std::string name) const {
  auto it = inventory.find(name);
  if (it == inventory.end())
    return nullptr;
  else
    return it->second;
}

void Container::addEntity(Entity* entity) {
  inventory[entity->getSpec()->getName()] = entity;
}

void Container::removeEntity(Entity* entity){
  inventory.erase(entity->getSpec()->getName());
}
