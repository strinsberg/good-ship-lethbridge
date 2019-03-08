/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-8
 */

#include "Inform.h"
#include "ObjectBlueprint.h"
#include <string>

Inform::Inform(std::istream& in, std::ostream& out) : Event(in, out) {}

Inform::~Inform() {}

std::string Inform::execute() {
  return message;
}

ObjectBlueprint* Inform::makeBlueprint() const {
  return new ObjectBlueprint();
}
