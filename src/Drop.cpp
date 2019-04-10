/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Drop.h"
#include <string>

Drop::Drop(Player* p) : Action(p) {}
Drop::~Drop() {}
std::string Drop::execute() {
  if (player->search(noun) == nullptr) {
    return "You don't have that!";
  } else {
    Entity* e = getEntity();

    if (e != nullptr && !e->getState()->getHidden()) {
      player->getCurrentRoom()->addEntity(e);
      player->removeEntity(e);
      return "You drop the " + noun;
    }
  }
}
