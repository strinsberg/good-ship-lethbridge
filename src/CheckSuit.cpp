#include "CheckSuit.h"
#include "Room.h"
#include "Suit.h"
#include "Player.h"
#include "Kill.h"
#include "ObjectBlueprint.h"
#include "Atmosphere.h"
#include <string>

CheckSuit::CheckSuit(Room* r, std::istream& is, std::ostream& os)
    : Event(is, os), here(r) {}

CheckSuit::~CheckSuit() {}

std::string CheckSuit::execute(Entity* affected) {
  if (Player* p = dynamic_cast<Player*>(affected)) {
    if (p->getEquipped() != nullptr
        && (here->getAtmosphere() == p->getEquipped()->getAtmosphere()
        || here->getAtmosphere() == Atmosphere::OXYGEN)) {
      return "Good thing you're wearing the right equipment!";
    } else {
      Kill k;
      message = k.execute(p);
      if (here->getAtmosphere() == Atmosphere::RADIATION)
        return "You are not protected from the radiation in this room!\n" + message;
      else if (here->getAtmosphere() == Atmosphere::SPACE)
        return "You are not wearing a space suit!\n" + message;
    }
  return "Only players can have suits so why are you checking for one?";
  }
}

ObjectBlueprint* CheckSuit::makeBlueprint() const {}

Room* CheckSuit::getHere() {
  return here;
}
