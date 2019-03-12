/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Door.h"
#include "ObjectBlueprint.h"
#include <string>

Door::Door() {}

Door::~Door() {}

std::string Door::describe() const {
  return spec->getName();
}

std::string Door::use(Entity* user) {
  return spec->getName();
}

ObjectBlueprint* Door::makeBlueprint() const {

}

void Door::setDestination(Room* room) {

}

Room* Door::getDestination() {

}
