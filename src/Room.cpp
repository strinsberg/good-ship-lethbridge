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

Room::Room() : atmosphere(Atmosphere::OXYGEN) {}

Room::~Room() {}

std::string Room::describe() const {
  std::stringstream ss;
  ss << "Location: " << spec->getName() << std::endl;
  ss << Container::describe();
  return ss.str();
}

std::string Room::enter(Entity* entity) {
  return "Enter Unimplemented";
}

Atmosphere Room::getAtmosphere() {
  return atmosphere;
}

void Room::setAtmosphere(Atmosphere a) {
  atmosphere = a;
}
