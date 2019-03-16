/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Suit.h"
#include "Atmosphere.h"
#include "Exceptions.h"
#include <string>
#include "gtest/gtest.h"
#include "Player.h"

TEST(TestSuit, use) {
  Suit*  s = new Suit();
  Player* p = new Player;
  p->addEntity(s);
  EXPECT_EQ("the suit is on you", s->use(p));
  delete p;
}

TEST(TestSuit, use_not_carrying) {
  Suit*  s = new Suit();
  Player* p = new Player;
  EXPECT_EQ("You need to be carrying a suit to use it!", s->use(p));
  delete p;
  delete s;
}

TEST(TestSuit, describe) {
  Suit s;
  s.getSpec()->setDescription("this is suit s");
  EXPECT_EQ("this is suit s", s.describe());
}

TEST(TestSuit, getAtmosphere) {
  Suit s;
  Atmosphere a = Atmosphere(SPACE);
  s.setAtmosphere(a);
  EXPECT_EQ(SPACE, s.getAtmosphere());
}
