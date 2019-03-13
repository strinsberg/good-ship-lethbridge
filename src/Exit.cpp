/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Exit.h"
#include "Entity.h"
#include "Door.h"
#include <string>

Exit::Exit(Player* p) : Action(p) {}
Exit::~Exit() {}

std::string Exit::execute() {
  Entity* e = player->getCurrentRoom()->search(noun);
  if (e != nullptr) {
    if (!e->getState()->getActive()) {
      return "For some reason you can't";
    }
    if (Door* d = dynamic_cast<Door*>(e)) {
      Room* r = d->getDestination();
      player->setCurrentRoom(r);
      return r->enter(player);
    }
    return noun + " is not an exit!";
  }
  return "There is no exit " + noun;
}
