/**
* @author
*
*/
#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"
#include "Inform.h"


Entity::Entity():spec(nullptr), state(nullptr), event(nullptr) {
  spec = new EntitySpec();
  state = new EntityState();
  event = new Inform();
}

Entity::~Entity() {
  delete spec;
  delete state;
  delete event;
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

void Entity::setEvent(Event* e) {
  delete event;
  event = e;
}

Event* Entity::getEvent() const {
  return event;
}
