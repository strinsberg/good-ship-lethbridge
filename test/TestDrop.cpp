/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-23
 */

#include "Drop.h"
#include "Exceptions.h"
#include <string>
#include "gtest/gtest.h"


TEST(DropTests, constructor_get) {
  Player* p = new Player("id7193");
  Drop d(p);
  EXPECT_EQ(d.getNoun(), "");
  EXPECT_EQ(d.getPlayer(), p);
  delete p;
}

TEST(DropTests, set_noun) {
  Player* p = new Player("id7193");
  Drop d(p);
  d.setNoun("Laser");
  EXPECT_EQ(d.getNoun(), "Laser");
  delete p;
}

TEST(DropTests, execute_player_has_item) {
  Player* p = new Player("id7193");
  Drop d(p);

  Room r("id7193");
  Container* c = new Container("id98u9");
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);
  p->setCurrentRoom(&r);

  d.setNoun("box");
  EXPECT_EQ("You drop the box", d.execute());
  EXPECT_EQ(c, r.search("box"));
  EXPECT_EQ(nullptr, p->search("box"));
  delete p;
}

TEST(DropTests, execute_room_has_item) {
  Player* p = new Player("id7193");
  Drop d(p);

  Room r("id7193");
  Container* c = new Container("idh98");
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p->setCurrentRoom(&r);

  d.setNoun("box");
  EXPECT_EQ("You don't have that!", d.execute());
  EXPECT_EQ(c, r.search("box"));
  EXPECT_EQ(nullptr, p->search("box"));
  delete p;
}

TEST(DropTests, execute_item_does_not_exits) {
  Player* p = new Player("id7193");
  Drop d(p);

  Room r("id7193");
  p->setCurrentRoom(&r);

  d.setNoun("box");
  EXPECT_EQ("You don't have that!", d.execute());
  delete p;
}
