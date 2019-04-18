/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"
#include <string>

EntitySpec::EntitySpec(): name(""), description("") {}

EntitySpec::EntitySpec(std::string i, std::string desc)
    : id(i), description(desc) {}

EntitySpec::~EntitySpec() {}

std::string EntitySpec::getName() const {
  return name;
}

void EntitySpec::setName(std::string n) {
  name = n;
}

std::string EntitySpec::getId() const {
  return id;
}

void EntitySpec::setId(std::string i) {
  id = i;
}

std::string EntitySpec::getDescription()const {
  return description;
}

void EntitySpec::setDescription(std::string n) {
  description = n;
}
