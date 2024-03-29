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

Inform::Inform(std::istream& is, std::ostream& os) : Event(is, os) {}

Inform::~Inform() {}

std::string Inform::execute(Entity* affected) {
  return message;
}

ObjectBlueprint* Inform::makeBlueprint() const {
  ObjectBlueprint* b = new ObjectBlueprint();

  b->setField("type", "inform");
  b->setField("message", message);
  if (spec != nullptr) {
    b->setField("name", spec->getName());
    std::string d = spec->isDone() ? "true" : "false";
    b->setField("done", d);
  }

  return b;
}
