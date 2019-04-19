/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"
#include "ObjectWithContentsBlueprint.h"
#include "Inform.h"
#include <string>


Entity::Entity():spec(nullptr), state(nullptr) {
  spec = new EntitySpec();
  state = new EntityState();
}

Entity::~Entity() {
  delete spec;
  delete state;
}

std::string Entity::describe() const {
  return spec->getDescription();
}

EntitySpec* Entity::getSpec() const {
  return spec;
}

void Entity::setSpec(EntitySpec* s) {
  delete spec;
  spec = s;
}

EntityState* Entity::getState() const {
  return state;
}

void Entity::setState(EntityState* s) {
  delete state;
  state = s;
}

void Entity::addEvent(std::string verb, Event* event) {
  auto it = events.find(verb);
  if (it != events.end())
    delete it->second;
  events[verb] = event;
}

std::string Entity::runEvent(std::string verb, Entity* user) {
  auto it = events.find(verb);
  if (it != events.end())
    return "Nothing happens";
  return it->second->execute(user);
}
