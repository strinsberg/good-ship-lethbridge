/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-21
 */

#include "Get.h"
#include <string>
#include <iostream>

Get::Get(Player* p) : Action(p) {}
Get::~Get() {}

std::string Get::execute() {
  if (player->search(noun) != nullptr) {
    return "You already have the " + noun;
  }

  Entity* e = player->getCurrentRoom()->search(noun);
  //std::cout << e->getSpec()->getName() << " " << e->getState() << " "<< e->getState()->getObtainable() << std::endl;

  if (e != nullptr) {
    if (!e->getState()->getObtainable()) {
      return "You can't take that!";
    } else if (!e->getState()->getHidden()) {
      player->addEntity(player->getCurrentRoom()->searchAndRemove(e->getSpec()->getId()));
      return "You get the " + noun;
    }
  }

  return "There is no " + noun;
}
