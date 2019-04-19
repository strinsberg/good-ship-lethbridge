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
