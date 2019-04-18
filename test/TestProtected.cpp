/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "Protected.h"
#include "Atmosphere.h"
#include "Suit.h"
#include "Player.h"
#include "Item.h"
#include "gtest/gtest.h"


TEST(ProtectedTests, constructor_and_test_true) {
  Protected pro(Atmosphere::RADIATION);
  Player* p = new Player();
  Suit* s = new Suit();
  s->setAtmosphere(Atmosphere::RADIATION);
  p->addEntity(s);
  s->use(p);
  EXPECT_TRUE(pro.test(p));
  delete p;
}

TEST(ProtectedTests, constructor_and_test_false) {
  Protected pro(Atmosphere::RADIATION);
  Player* p = new Player();
  Suit* s = new Suit();
  s->setAtmosphere(Atmosphere::OXYGEN);
  p->addEntity(s);
  s->use(p);
  EXPECT_FALSE(pro.test(p));
  delete p;
}

TEST(ProtectedTests, constructor_and_test_no_suit) {
  Protected pro(Atmosphere::RADIATION);
  Player* p = new Player();
  EXPECT_FALSE(pro.test(p));
  delete p;
}

TEST(ProtectedTests, constructor_and_test_not_player) {
  Protected pro(Atmosphere::RADIATION);
  Item* p = new Item();
  EXPECT_FALSE(pro.test(p));
  delete p;
}
