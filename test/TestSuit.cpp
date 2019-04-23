/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#include "Suit.h"
#include "Atmosphere.h"
#include "Exceptions.h"
#include "Entity.h"
#include <string>
#include "gtest/gtest.h"
#include "Player.h"

TEST(TestSuit, use) {
  Suit*  s = new Suit();
  s->getSpec()->setId("suit123");
  s->getSpec()->setName("hazmat suit");
  Player* p = new Player("id7193");
  p->addEntity(s);
  EXPECT_EQ("You are now wearing the hazmat suit", s->runEvent("use", p));
  delete p;
}

TEST(TestSuit, use_not_a_player) {
  Suit*  s = new Suit();
  s->getSpec()->setId("suit123");
  s->getSpec()->setName("hazmat suit");
  Entity* p = new Entity();
  EXPECT_EQ("That can't wear a suit!", s->runEvent("use", p));
  delete p;
}

TEST(TestSuit, use_not_carrying) {
  Suit*  s = new Suit();
  s->getSpec()->setId("suit123");
  s->getSpec()->setName("hazmat suit");
  Player* p = new Player("id7193");
  EXPECT_EQ("You need to be carrying a suit to equip it!", s->runEvent("use", p));
  delete p;
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
