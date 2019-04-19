/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Door.h"
#include "Player.h"
#include "TransferItem.h"
#include <sstream>
#include <typeinfo>
#include <string>

Door::Door() : destination(nullptr), here(nullptr) {}

Door::Door(std::string id) : Entity(id), destination(nullptr), here(nullptr) {
  this->addEvent("use", new MoveEntity("hidden1472342", destination, here));
}

Door::~Door() {}

std::string Door::describe() const {
  return spec->getDescription();
}

void Door::setDestination(Room* room) {
  auto it = events.find("use");
  it->second->here = room;
  destination = room;
}

Room* Door::getDestination() {
  return destination;
}

void Door::setHere(Room* room) {
  events["use"]->here = room;
  here = room;
}

Room* Door::getHere() {
  return here;
}
