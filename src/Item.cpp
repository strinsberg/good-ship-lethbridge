/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Item.h"
#include "ObjectBlueprint.h"
#include <string>

Item::Item() {}

Item::~Item() {}

std::string Item::describe() const {
  return spec->getDescription();
}

std::string Item::use(Entity* user) {
  return event->execute(user);
}

ObjectBlueprint* Item::makeBlueprint() const {

}
