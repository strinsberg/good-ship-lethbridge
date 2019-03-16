/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Get.h"
#include <string>

Get::Get(Player* p) : Action(p) {}
Get::~Get() {}

std::string Get::execute() {
  if (player->search(noun) != nullptr) {
    return "You already have the " + noun;
  }

  Entity* e = getEntity();

  if (e != nullptr) {
    if (!e->getState()->getObtainable()) {
      return "You can't take that!";
    } else if (!e->getState()->getHidden()) {
      Container* owner =
          static_cast<Container*>(player->getCurrentRoom()->findOwner(noun));
      owner->removeEntity(e);
    }

      player->addEntity(e);
      return "You get the " + noun;
  }

  return "There is no " + noun;
}
