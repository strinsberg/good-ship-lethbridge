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

void Entity::setEvent(Event* e) {
  delete event;
  event = e;
}

Event* Entity::getEvent() const {
  return event;
}

ObjectBlueprint* Entity::makeBlueprint() const {
  ObjectWithContentsBlueprint* bp = new ObjectWithContentsBlueprint();

  bp->setField("type", "entity");
  bp->setField("description", spec->getDescription());
  bp->setField("name", spec->getName());

  std::string act = state->getActive() ? "true" : "false";
  bp->setField("active", act);
  std::string obt = state->getObtainable() ? "true" : "false";
  bp->setField("obtainable", obt);
  std::string hid = state->getHidden() ? "true" : "false";
  bp->setField("hidden", hid);

  ObjectBlueprint* ebp = event->makeBlueprint();
  ebp->setField("owner", spec->getName());
  bp->addBlueprint(ebp);

  return bp;
}
