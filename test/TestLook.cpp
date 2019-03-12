/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include <string>
#include "gtest/gtest.h"

TEST(LookTests, constructor_get) {
  Player* p = new Player();
  Look l(p);
  EXPECT_EQ(l.getNoun(), "");
  EXPECT_EQ(l.getPlayer(), p);
  delete p;
}

TEST(LookTests, set_noun) {
  Player* p = new Player();
  Look l(p);
  l.setNoun("Laser");
  EXPECT_EQ(l.getNoun(), "Laser");
  delete p;
}

TEST(LookTests, execute_player_has_item) {
  Player* p = new Player();
  Look l(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);
  p->setCurrentRoom(&r);

  l.setNoun("box");
  EXPECT_EQ(l.execute(), "You see a box");
  delete p;
}

TEST(LookTests, execute_room_has_item) {
  Player* p = new Player();
  Look l(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p->setCurrentRoom(&r);

  l.setNoun("box");
  EXPECT_EQ(l.execute(), "You see a box");
  delete p;
}

TEST(LookTests, execute_no_item) {
  Player* p = new Player();
  Look l(p);

  Room r;
  p->setCurrentRoom(&r);

  l.setNoun("box");
  EXPECT_EQ(l.execute(), "There is no box");
  delete p;
}
