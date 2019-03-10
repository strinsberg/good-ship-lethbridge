/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Use.h"
#include <string>


Use::Use() {}

Use::~Use() {}

std::string Use::execute() {
  Entity* e = getEntity();

  if (e != nullptr) {
    if (!e->getState()->getActive())
      return "For some reason you can't";
    else if (!e->getState()->getHidden())
      return e->use(player);
  }

  return "There is no " + noun;
}
