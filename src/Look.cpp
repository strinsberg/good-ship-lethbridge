/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include "Entity.h"
#include "Exceptions.h"
#include <string>

Look::Look(Player* p) : Action(p) {}

Look::~Look() {}

std::string Look::execute() {
  if (noun == "")
    return player->getCurrentRoom()->describe();

  Entity* e = getEntity();

  std::string str("You see ");
  if (e != nullptr) {
    if (e->hasEvent("look"))
      return e->runEvent("look", player);
    else
      return str + e->getSpec()->getDescription();
  }

  return "There is no " + noun;
}
