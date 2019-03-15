/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Room.h"
#include "Entity.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "ObjectWithContentsBlueprint.h"
#include "Exceptions.h"
#include <string>
#include <sstream>

Room::Room() : atmosphere(Atmosphere::OXYGEN),
  enterEvent(nullptr) {}

Room::~Room() {
  if (enterEvent != nullptr)
    delete enterEvent;
}

std::string Room::describe() const {
  std::stringstream ss;
  ss << "Location: " << spec->getName() << std::endl;
  ss << Container::describe();
  return ss.str();
}

std::string Room::use(Entity*) {
  return "You can't use a room!";
}

ObjectBlueprint* Room::makeBlueprint() const {
  ObjectWithContentsBlueprint* bp = static_cast<ObjectWithContentsBlueprint*>
                                    (Container::makeBlueprint());

  bp->setField("type", "room");
  bp->setField("atmosphere",
               std::to_string(atmosphere));  // might need a different conversion

  if (enterEvent != nullptr)
    bp->addBlueprint(enterEvent->makeBlueprint());

  return bp;
}

std::string Room::enter(Entity* entity) {
  if (enterEvent == nullptr)
    return "";
  return enterEvent->execute(entity);
}


void Room::setEnter(Event* event) {
  enterEvent = event;
}


Atmosphere Room::getAtmosphere() {
  return atmosphere;
}

void Room::setAtmosphere(Atmosphere a) {
  atmosphere = a;
}
