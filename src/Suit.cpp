/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include"Suit.h"
#include"Player.h"
#include "ObjectBlueprint.h"
#include "Atmosphere.h"
#include <typeinfo>
#include <string>

Suit::Suit() : atmosphere(Atmosphere::OXYGEN) {}
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
