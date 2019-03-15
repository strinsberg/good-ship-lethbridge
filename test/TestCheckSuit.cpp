/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-13
 */

#include "CheckSuit.h"
#include "Suit.h"
#include "Event.h"
#include "Item.h"
#include "Container.h"
#include "Player.h"
#include "Atmosphere.h"
#include <string>
#include "gtest/gtest.h"

TEST(CheckSuitTests, constructor_get) {
  Room* r = new Room();
  CheckSuit cs(r);
  EXPECT_EQ("", cs.getMessage());
  EXPECT_EQ(false, cs.getSpec()->isDone());
  EXPECT_EQ(r, cs.getHere());
  delete r;
}

TEST(CheckSuitTests, player_no_suit_oxygen) {
  Room* r = new Room();
  CheckSuit cs(r);
  Player* p = new Player();
  Suit* s = new Suit();
  p->addEntity(s);
  s->use(p);

  EXPECT_EQ(s, p->getEquipped());
  EXPECT_EQ("Good thing you're wearing the right equipment!", cs.execute(p));
  EXPECT_EQ(false, p->getState()->getHidden());
  delete r;
  delete p;
}

TEST(CheckSuitTests, player_suit_radiation) {
  Room* r = new Room();
  r->setAtmosphere(Atmosphere::RADIATION);
  CheckSuit cs(r);

  Player* p = new Player();
  Suit* s = new Suit();
  s->setAtmosphere(Atmosphere::RADIATION);
  p->addEntity(s);
  s->use(p);

  EXPECT_EQ(s, p->getEquipped());
  EXPECT_EQ("Good thing you're wearing the right equipment!", cs.execute(p));
  EXPECT_EQ(false, p->getState()->getHidden());
  delete r;
  delete p;
}

TEST(CheckSuitTests, player_suit_space) {
  Room* r = new Room();
  r->setAtmosphere(Atmosphere::SPACE);
  CheckSuit cs(r);

  Player* p = new Player();
  Suit* s = new Suit();
  s->setAtmosphere(Atmosphere::SPACE);
  p->addEntity(s);
  s->use(p);

  EXPECT_EQ(s, p->getEquipped());
  EXPECT_EQ("Good thing you're wearing the right equipment!", cs.execute(p));
  EXPECT_EQ(false, p->getState()->getHidden());
  delete r;
  delete p;
}

TEST(CheckSuitTests, player_wrong_suit_space) {
  Room* r = new Room();
  r->setAtmosphere(Atmosphere::SPACE);
  CheckSuit cs(r);

  Player* p = new Player();
  p->getSpec()->setName("Steve");
  Suit* s = new Suit();
  s->setAtmosphere(Atmosphere::RADIATION);
  p->addEntity(s);
  s->use(p);

  EXPECT_EQ(s, p->getEquipped());
  EXPECT_EQ("you suffocate in space!\nYou are not wearing the right protective suit!\nSteve is Dead!", cs.execute(p));
  EXPECT_EQ(true, p->getState()->getHidden());
  delete r;
  delete p;
}

TEST(CheckSuitTests, player_no_suit_radiation) {
  Room* r = new Room();
  r->setAtmosphere(Atmosphere::RADIATION);
  CheckSuit cs(r);

  Player* p = new Player();
  p->getSpec()->setName("Steve");;

  EXPECT_EQ(nullptr, p->getEquipped());
  EXPECT_EQ("The radiation burns you up!\nYou are not wearing the right protective suit!\nSteve is Dead!", cs.execute(p));
  EXPECT_EQ(true, p->getState()->getHidden());
  delete r;
  delete p;
}
