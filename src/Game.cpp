/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Game.h"
#include "Player.h"
#include "Room.h"
#include <string>


Game::Game() {

}

Game::~Game() {

}

void Game::run() {

}

Player& Game::getPlayer() const {
  return *player;
}

void Game::setPlayer(Player* p) {

}

Room* Game::getRoom(std::string name) const {
  Room* r;
  return r;
}

void Game::addRoom(Room* room) {

}
