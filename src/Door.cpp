/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Door.h"
#include "ObjectBlueprint.h"
#include "Player.h"
#include <typeinfo>
#include <string>

Door::Door() : destination(nullptr) {}

Door::~Door() {}

std::string Door::describe() const {
  return spec->getDescription();
}

std::string Door::use(Entity* user) {
  if (!state->getActive())
    return "For some reason it doesn't work";


  if (Player* p = dynamic_cast<Player*>(user)) {
    p = (Player*)user;
    p->setCurrentRoom(destination);
    return "You use " + spec->getName();
  } else {
    // check entity is in room???
    here->removeEntity(user);
    destination->addEntity(user);
    return user->getSpec()->getName() + " uses " + spec->getName();
  }
}

ObjectBlueprint* Door::makeBlueprint() const {
  ObjectBlueprint* bp = Entity::makeBlueprint();
  bp->setField("type", "door");
  bp->setField("here", here->getSpec()->getName());
  bp->setField("destination", destination->getSpec()->getName());
  return bp;
}

void Door::setDestination(Room* room) {
  destination = room;
}

Room* Door::getDestination() {
  return destination;
}

void Door::setHere(Room* room) {
  here = room;
}

Room* Door::getHere() {
  return here;
}
