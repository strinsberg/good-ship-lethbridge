/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "Parser.h"
#include "Command.h"
#include "Exceptions.h"
#include <string>
#include <map>
#include <iostream>

using std::map;
using std::string;

Game::Game(std::istream& is, std::ostream& os)
    : rooms(map<string, Room*>()), player(nullptr), in(is), out(os), running(true) {
  // Create a player with a blank spec
  player = new Player();
  EntitySpec* spec = new EntitySpec();
  spec->setName("None");
  spec->setDescription("None");
  player->setSpec(spec);
  spec = nullptr;
}

Game::~Game() {
  delete player;
  for (auto r : rooms)
    delete r.second;
}

Player* Game::getPlayer() const {
  return player;
}

void Game::setPlayer(Player* p) {
  delete player;
  player = p;
}

Room* Game::getRoom(const std::string& name) {
  auto it = rooms.find( toLower(name) );
  if (it == rooms.end())
    return nullptr;
  return it->second;
}

void Game::addRoom(const string& name, Room* room) {
  if (rooms.find( toLower(name) ) != rooms.end())
    throw invalid_parameter_error("There is a room with that name already!");
  rooms[ toLower(name) ] = room;
}

int Game::numRooms() {
  return rooms.size();
}

bool Game::isRunning() {
  return running;
}

void Game::stop() {
  running = false;
}

void Game::run() {
  while (running) {
    std::string input;
    out << "> ";
    std::getline(in, input);

    input = toLower(input);

    Command* c;
    if (input != "") {
      Parser p(input, this);
      c = p.parse();
      out << c->execute() << std::endl;
      delete c;
    }

    if (player->getState()->getHidden()) {
      out << "Game Over!" << std::endl;
      out << "Better luck next time!" << std::endl;
      running = false;
    }
  }
}

string Game::toLower(const string& str) {
  string lower;
  for (auto c : str)
    lower.push_back( tolower(c) );
  return lower;
}

std::map<std::string, Room*> Game::getRooms() {
  return rooms;
}
