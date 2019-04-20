/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#include "Use.h"
#include <string>
#include <sstream>


Use::Use(Player* p) : Action(p) {}

Use::~Use() {}

std::string Use::execute() {
  Entity* e = getEntity();

  if (e != nullptr) {
    return e->runEvent("use", player);
  }

  return "There is no " + noun;
}
