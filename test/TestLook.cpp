/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include <string>
#include "gtest/gtest.h"

TEST(LookTests, constructor_get) {
  Look l;
  EXPECT_EQ(l.getNoun(), "");
  EXPECT_EQ(l.getPlayer(), nullptr);
}

TEST(LookTests, set_noun) {
  Look l;
  l.setNoun("Laser");
  EXPECT_EQ(l.getNoun(), "Laser");
}

TEST(LookTests, set_player) {
  Look l;
  Player* p = new Player();
  l.setPlayer(p);
  EXPECT_EQ(l.getPlayer(), p);
  delete p;
}

TEST(LookTests, execute_player_has_item) {
  Look l;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);
  p.setCurrentRoom(&r);

  l.setPlayer(&p);
  l.setNoun("box");
  EXPECT_EQ(l.execute(), "You see a box");
}

TEST(LookTests, execute_room_has_item) {
  Look l;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p.setCurrentRoom(&r);

  l.setPlayer(&p);
  l.setNoun("box");
  EXPECT_EQ(l.execute(), "You see a box");
}

TEST(LookTests, execute_no_item) {
  Look l;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  l.setPlayer(&p);
  l.setNoun("box");
  EXPECT_EQ(l.execute(), "There is no box");
}
