/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-8
 */

#include "Inform.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>

Inform::Inform(std::string id, std::string msg) : Event(id), message(msg) {}

Inform::~Inform() {}

std::string Inform::execute(Entity* affected) {
  return message;
}
