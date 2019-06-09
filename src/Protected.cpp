/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-20
 */

#include "Protected.h"
#include "Atmosphere.h"
#include "Suit.h"
#include "Player.h"
#include "Entity.h"

Protected::Protected(Atmosphere a) : atmosphere(a) {}

Protected::~Protected() {}

bool Protected::test(Entity* target) const {
  if (Player* p = dynamic_cast<Player*>(target)) {
    Suit* suit = p->getSuit();
    if (suit != nullptr)
      return suit->getAtmosphere() == atmosphere;
    else
      return false;
  } else {
    return false;
  }
}
