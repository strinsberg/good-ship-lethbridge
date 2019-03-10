/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Action.h"
#include "Entity.h"
#include "Player.h"
#include "Exceptions.h"

Action::Action() : player(nullptr) {}
Action::~Action() {}

void Action::setPlayer(Player* p) {
  player = p;
}

const Player* Action::getPlayer() const {
  return player;
}

Entity* Action::getEntity() {
  if (player == nullptr)
    throw unfinished_object_error("Action has no Player!");

  Entity* e = player->search(noun);
  if (e != nullptr)
    return e;

  e = player->getCurrentRoom()->search(noun);
  if (e != nullptr)
    return e;

  return nullptr;
}
