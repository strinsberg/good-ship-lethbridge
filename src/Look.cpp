/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include "Entity.h"
#include "Exceptions.h"
#include <string>

Look::Look() {}

Look::~Look() {}

std::string Look::execute() {
  Entity* e = getEntity();

  std::string str("You see ");
  if (e != nullptr)
    return str + e->getSpec()->getDescription();

  return "There is no " + noun;
}
