/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Use.h"
#include "Activate.h"
#include <string>


Use::Use(Player* p) : Action(p) {}

Use::~Use() {}

std::string Use::execute() {
  Entity* e = getEntity();
/*
  if (e != nullptr) {
    if (!e->getState()->getActive()) {
      if (Activate* a = dynamic_cast<Activate*>(e->getEvent()))
        return e->getEvent()->execute(player);
      else
        return "For some reason you can't";
    } else if (!e->getState()->getHidden()) {
      return e->use(player);}
  }
*/
  return "There is no " + noun;
}
