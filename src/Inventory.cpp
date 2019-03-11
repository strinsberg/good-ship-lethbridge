/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Inventory.h"
#include <string>
#include <sstream>
#include <iostream>

Inventory::Inventory() {}
Inventory::~Inventory() {}
std::string Inventory::execute() {
  if (player->begin() == player->end())
    return "You don't have anything!";

  if (noun == "") {
    std::stringstream ss;
    ss << "You have:" << std::endl;

    for (auto it = player->begin(); it != player->end(); it++) {
      ss << it->first << " -> " << it->second->describe();

      it++;
      if (it != player->end())
        ss << std::endl;
      it--;  // This is gross
    }
    return ss.str();
  }

  if (player->search(noun) != nullptr)
    return "You have that";

  return "You don't have that";
}
