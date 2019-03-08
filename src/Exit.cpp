/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Exit.h"
#include "Entity.h"
#include <string>

Exit::Exit() {}
Exit::~Exit() {}

std::string Exit::execute() {
  return noun;  // for tdd
}
