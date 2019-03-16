/**
* @author
*
*/
#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"
#include <string>

EntitySpec::EntitySpec(): name(""), description("") {}

EntitySpec::~EntitySpec() {}

bool EntitySpec::matches(std::string n) const {
  if (n == name)
    return true;
  else
    return false;
}

std::string EntitySpec::getName() const {
  return name;
}

void EntitySpec::setName(std::string n) {
  name = n;
}

std::string EntitySpec::getDescription()const {
  return description;
}

void EntitySpec::setDescription(std::string n) {
  description = n;
}
