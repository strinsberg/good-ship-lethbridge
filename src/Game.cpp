/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */
#include "Game.h"
#include "Player.h"
#include "Room.h"
#include <string>
#include <map>

using std::map;
using std::string;

Game::Game(std::istream& is, std::ostream& os)
  : rooms(map<string, Room*>()), player(nullptr), in(is), out(os), running(true) {}

Game::~Game() {
  /*if (player != nullptr)
    delete player;
  for (auto r : rooms)
    if (r.second != nullptr)
      delete r.second;*/
}

void Game::run() {}

Player* Game::getPlayer() const {
  return player;
}

void Game::setPlayer(Player* p) {
  player = p;
}

Room* Game::getRoom(std::string name) const {
  return rooms.find(name)->second;
}

void Game::addRoom(const string& name, Room* room) {
  rooms[name] = room;
}

int Game::numRooms() {
  return rooms.size();
}
