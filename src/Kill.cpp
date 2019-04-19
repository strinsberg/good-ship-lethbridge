/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Kill.h"
#include "Entity.h"
#include <sstream>
#include <iostream>
#include <string>

Kill::Kill(std::string id, std::string message) : Inform(id, message) {}

Kill::~Kill() {}

std::string Kill::execute(Entity* affected) {
  std::stringstream ss;
  affected->getState()->setHidden(true);
  ss << message << std::endl;
  ss << affected->getSpec()->getName() << " is Dead!";
  return ss.str();
}
