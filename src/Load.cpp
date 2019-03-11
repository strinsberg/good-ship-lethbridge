/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Load.h"
#include "Game.h"
#include <string>

Load::Load(Game* g) :GameCommand(g) {}
Load::~Load() {}
std::string Load::execute() {
  return noun;
}
