/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Save.h"
#include "Game.h"
#include <string>

Save::Save(Game* g) :GameCommand(g) {}
Save::~Save() {}
std::string Save::execute() {
  return noun;
}
