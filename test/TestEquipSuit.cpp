/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-20
 */

#include "EquipSuit.h"
#include "Suit.h"
#include "Player.h"
#include "Container.h"
#include <string>
#include "gtest/gtest.h"

TEST(EquipSuitTests, execute) {
  Suit* suit = new Suit();
  suit->getSpec()->setName("hazmat suit");
  EquipSuit es("equip123", suit);

  Player* p = new Player("player123");
  p->addEntity(suit);

  EXPECT_EQ("You are now wearing the hazmat suit", es.execute(p));
  delete p;
}

TEST(EquipSuitTests, execute_not_carrying_suit) {
  Suit* suit = new Suit();
  suit->getSpec()->setName("hazmat suit");
  EquipSuit es("equip123", suit);

  Player* p = new Player("player123");

  EXPECT_EQ("You need to be carrying a suit to equip it!", es.execute(p));
  delete p;
}

TEST(EquipSuitTests, execute_not_a_player) {
  Suit* suit = new Suit();
  suit->getSpec()->setName("hazmat suit");
  EquipSuit es("equip123", suit);

  Container* p = new Container("player123");
  p->addEntity(suit);

  EXPECT_EQ("That can't wear a suit!", es.execute(p));
  delete p;
}
