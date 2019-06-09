/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#include"Suit.h"
#include"Player.h"
#include "Atmosphere.h"
#include "EquipSuit.h"
#include <typeinfo>
#include <string>

Suit::Suit(Atmosphere atmos) : atmosphere(atmos) {
  addEvent("use", new EquipSuit("hidden45824987", this));
}

Suit::~Suit() {}

std::string Suit::describe() const {
  return spec->getDescription();
}

Atmosphere Suit::getAtmosphere() {
  return atmosphere;
}

void Suit::setAtmosphere(Atmosphere a) {
  atmosphere = a;
}
