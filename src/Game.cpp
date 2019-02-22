/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Game.h"
#include "Player.h"
#include "Room.h"
#include <string>
#include <map>

using std::map;
using std::string;

Game::Game() : rooms(map<string, Room*>()), player(nullptr) {

}

Game::~Game() {
  delete player;
  for (auto r : rooms)
    delete r.second;
}

void Game::run() {

}

Player* Game::getPlayer() const {
  return player;
}

void Game::setPlayer(Player* p) {

}

Room* Game::getRoom(std::string name) const {
  return nullptr;
}

void Game::addRoom(Room* room) {

}

int Game::numRooms() {
  return rooms.size();
}
