/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Talk.h"
#include "Entity.h"
#include "Npc.h"
#include <string>


Talk::Talk(Player* p) : Action(p) {}
Talk::~Talk() {}
std::string Talk::execute() {
  Entity* e = player->getCurrentRoom()->search(noun);
  if (e == nullptr)
    return "There is no " + noun;

  if (Npc* npc = dynamic_cast<Npc*>(e)) {
    if (npc->getState()->getActive()) {
      return npc->use(player);
    } else {
      return noun + " can't talk right now";
    }
  }
  return "You can't talk to " + noun;
}
