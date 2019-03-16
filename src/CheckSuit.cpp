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
      k.setMessage("You are not wearing the right protective suit!");
      message = k.execute(p);
      if (here->getAtmosphere() == Atmosphere::RADIATION)
        return "The radiation burns you up!\n" + message;
      else if (here->getAtmosphere() == Atmosphere::SPACE)
        return "you suffocate in space!\n" + message;
    }
  }
  return "Only players can have suits so why are you checking for one?";
}

ObjectBlueprint* CheckSuit::makeBlueprint() const {
  ObjectBlueprint* bp = new ObjectBlueprint();
  bp->setField("type", "checksuit");
  bp->setField("message", message);
  bp->setField("name", spec->getName());
  std::string done = spec->isDone() ? "true" : "false";
  bp->setField("done", done);
  bp->setField("here", here->getSpec()->getName());
  return bp;
}

Room* CheckSuit::getHere() {
  return here;
}
