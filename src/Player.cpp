/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-10
 */

#include "Player.h"
#include "Room.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include <string>

Player::Player() : currentRoom(nullptr) {}

Player::~Player() {}

std::string Player::describe() const{
  return spec->getDescription();
}

std::string Player::use(Entity*) {
  return "Have some self respect! Don't use yourself!";
}

Room* Player::getCurrentRoom() const {
  return currentRoom;
}

void Player::setCurrentRoom(Room* r) {
  currentRoom = r;
}

ObjectBlueprint* Player::makeBlueprint() const {
}
