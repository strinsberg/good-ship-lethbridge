/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-10, 2019-04-20
 */

#include "Player.h"
#include "Room.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "ObjectWithContentsBlueprint.h"
#include <string>

Player::Player() : currentRoom(nullptr), suit(nullptr) {}

Player::Player(std::string id) : Container(id), currentRoom(nullptr), suit(nullptr) {}

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

void Player::wearSuit(Suit* s) {
  removeSuit();
  suit = s;
}

Suit* Player::getSuit() {
  return suit;
}

void Player::removeSuit() {
  if (suit != nullptr) {
    addEntity(suit);
    suit = nullptr;
  }
}
