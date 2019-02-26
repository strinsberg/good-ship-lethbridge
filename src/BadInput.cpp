/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "BadInput.h"
#include <string>

BadInput::BadInput() {}
BadInput::~BadInput() {}

std::string BadInput::execute() {
  return "You can't " + noun + "!";
}
