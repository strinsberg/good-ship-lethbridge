/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Door.h"
#include "ObjectBlueprint.h"
#include "Player.h"
#include <sstream>
#include <typeinfo>
#include <string>

Door::Door() : destination(nullptr), here(nullptr) {}

Door::~Door() {}

std::string Door::describe() const {
  return spec->getDescription();
}

std::string Door::use(Entity* user) {
  if (!state->getActive())
    return "For some reason it doesn't work";

  if (destination == nullptr)
    return "The door leads nowhere";


  std::stringstream ss;
  if (Player* p = dynamic_cast<Player*>(user)) {
    p->setCurrentRoom(destination);
    ss << "You use " << spec->getName() << std::endl;
    ss << destination->enter(p);
    return ss.str();
  } else {
    // check entity is in room???
    here->removeEntity(user);
    destination->addEntity(user);
    ss << user->getSpec()->getName();
    ss << " uses " << spec->getName()  << std::endl;
    ss << destination->enter(p);
    return ss.str();
  }
}

ObjectBlueprint* Door::makeBlueprint() const {
  ObjectBlueprint* bp = Entity::makeBlueprint();
  bp->setField("type", "door");
  std::string h = here == nullptr ? "" : here->getSpec()->getName();
  bp->setField("here", h);
  std::string d =
      destination == nullptr ? "" : destination->getSpec()->getName();
  bp->setField("destination", d);
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
