/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Npc.h"
#include "Container.h"
#include <string>

Npc::Npc() {}

Npc::~Npc() {}

std::string Npc::describe()const {
  return spec->getDescription();
}
