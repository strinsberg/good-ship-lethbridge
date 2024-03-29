/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Get.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(GetTests, constructor_get) {
  Player* p = new Player();
  Get g(p);
  EXPECT_EQ(g.getNoun(), "");
  EXPECT_EQ(g.getPlayer(), p);
  delete p;
}

TEST(GetTests, set_noun) {
  Player* p = new Player();
  Get g(p);
  g.setNoun("Laser");
  EXPECT_EQ(g.getNoun(), "Laser");
  delete p;
}

TEST(GetTests, execute_room_has_item) {
  Player* p = new Player();
  Get g(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p->setCurrentRoom(&r);

  g.setNoun("box");
  EXPECT_EQ("You get the box", g.execute());
  EXPECT_EQ(nullptr, r.search("box"));
  EXPECT_EQ(c, p->search("box"));
  delete p;
}


TEST(GetTests, execute_room_has_item_not_obtainable) {
  Player* p = new Player();
  Get g(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  c->getState()->setObtainable(false);
  r.addEntity(c);
  p->setCurrentRoom(&r);

  g.setNoun("box");
  EXPECT_EQ("You can't take that!", g.execute());
  delete p;
}

TEST(GetTests, execute_player_has_item) {
  Player* p = new Player();
  Get g(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);
  p->setCurrentRoom(&r);

  g.setNoun("box");
  EXPECT_EQ("You already have the box", g.execute());
  EXPECT_EQ(nullptr, r.search("box"));
  EXPECT_EQ(c, p->search("box"));
  delete p;
}

TEST(GetTests, execute_item_does_not_exist) {
  Player* p = new Player();
  Get g(p);

  Room r;
  p->setCurrentRoom(&r);

  g.setNoun("box");
  EXPECT_EQ("There is no box", g.execute());
  delete p;
}
