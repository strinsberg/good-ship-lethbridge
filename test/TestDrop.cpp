/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Drop.h"
#include <string>
#include "gtest/gtest.h"

TEST(DropTests, constructor_get) {
  Drop d;
  EXPECT_EQ(d.getNoun(), "");
  EXPECT_EQ(d.getPlayer(), nullptr);
}

TEST(DropTests, set_noun) {
  Drop d;
  d.setNoun("Laser");
  EXPECT_EQ(d.getNoun(), "Laser");
}

TEST(DropTests, set_player) {
  Drop d;
  Player* p = new Player();
  d.setPlayer(p);
  EXPECT_EQ(d.getPlayer(), p);
  delete p;
}

TEST(DropTests, execute_player_has_item) {
  Drop d;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);
  p.setCurrentRoom(&r);

  d.setPlayer(&p);
  d.setNoun("box");
  EXPECT_EQ("You drop the box", d.execute());
  EXPECT_EQ(c, r.search("box"));
  EXPECT_EQ(nullptr, p.search("box"));
}

TEST(DropTests, execute_room_has_item) {
  Drop d;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p.setCurrentRoom(&r);

  d.setPlayer(&p);
  d.setNoun("box");
  EXPECT_EQ("You don't have that!", d.execute());
  EXPECT_EQ(c, r.search("box"));
  EXPECT_EQ(nullptr, p.search("box"));
}

TEST(DropTests, execute_item_does_not_exits) {
  Drop d;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  d.setPlayer(&p);
  d.setNoun("box");
  EXPECT_EQ("There is no box", d.execute());
}
