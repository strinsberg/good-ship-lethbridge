/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12, 2019-04-20
 */

#include "Door.h"
#include "Player.h"
#include "MovePlayer.h"
#include <sstream>
#include <typeinfo>
#include <string>


Door::Door(std::string id, Room* h, Room* d)
    : Entity(id), destination(d), here(h) {
  addEvent("use", new MovePlayer("hidden1472342", this));
}

Door::~Door() {}

std::string Door::describe() const {
  return spec->getDescription();
}

Room* Door::getDestination() {
  return destination;
}

Room* Door::getHere() {
  return here;
}
