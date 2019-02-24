/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Action.h"
#include "Player.h"

Action::Action() : player(nullptr) {};
Action::~Action() {}

void Action::setPlayer(Player* p) {
  player = nullptr;
}

const Player* Action::getPlayer() const {
  return player;
}
