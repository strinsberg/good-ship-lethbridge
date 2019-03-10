/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Inventory.h"
#include <string>

Inventory::Inventory() {}
Inventory::~Inventory() {}
std::string Inventory::execute() {
  return noun;
}
