/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#include "Talk.h"
#include "Entity.h"
#include "Npc.h"
#include <string>


Talk::Talk(Player* p) : Action(p) {}

Talk::~Talk() {}

std::string Talk::execute() {
  Entity* e = getEntity();
  if (e != nullptr){
    if (e->getState()->getActive())
      return e->runEvent("talk", player);
    else
      return noun + " can't talk right now";
  } else {
    return "There is no " + noun + "!";
  }
}
