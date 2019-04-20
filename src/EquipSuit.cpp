/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-20
 */

#include "EquipSuit.h"
#include "Player.h"
#include <string>

EquipSuit::EquipSuit(std::string id, Suit* owner) : Event(id), suit(owner) {}

EquipSuit::~EquipSuit() {}

std::string EquipSuit::execute(Entity* e) {
  if (Player* player = dynamic_cast<Player*>(e)) {
    if (player->searchById(suit->getSpec()->getId()) != nullptr) {
      player->removeEntity(suit);
      player->setEquipped(suit);
      return "You are now wearing the " + suit->getSpec()->getName();
    } else {
      return "You need to be carrying a suit to equip it!";
    }
  } else {
    return "That can't wear a suit!";
  }
}
