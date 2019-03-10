/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Action.h"
#include "Player.h"

Action::Action() : player(nullptr) {}
Action::~Action() {}

void Action::setPlayer(Player* p) {
  player = p;
}

const Player* Action::getPlayer() const {
  return player;
}
