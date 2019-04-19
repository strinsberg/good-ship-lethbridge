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
#include "ObjectWithContentsBlueprint.h"
#include <string>

Player::Player() : currentRoom(nullptr), equipped(nullptr) , suit(nullptr) {}

Player::~Player() {
    if (suit != nullptr)
        delete suit;
}

std::string Player::describe() const {
  return spec->getDescription();
}

Room* Player::getCurrentRoom() const {
  return currentRoom;
}

void Player::setCurrentRoom(Room* r) {
  currentRoom = r;
}

void Player::setEquipped(Suit* s) {
  equipped = s;
}

Suit* Player::getEquipped() {
  return equipped;
}
