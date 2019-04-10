/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Action.h"
#include "Entity.h"
#include "Player.h"
#include "Exceptions.h"
#include <string>

Action::Action(Player* p) : player(p) {}
Action::~Action() {}

const Player* Action::getPlayer() const {
  return player;
}

Entity* Action::findEntity(Player* p, std::string n) {
  if (p == nullptr)
    throw unfinished_object_error("Action has no Player!");

  Entity* e = p->search(n);
  if (e != nullptr)
    return e;

  e = p->getCurrentRoom()->search(n);
  if (e != nullptr)
    return e;

  return nullptr;
}

Entity* Action::getEntity() {
  return findEntity(player, noun);
}
