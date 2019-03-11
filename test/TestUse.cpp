/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Use.h"
#include "Exceptions.h"
#include "Room.h"
#include "Player.h"
#include "Container.h"
#include <string>
#include "gtest/gtest.h"

TEST(UseTests, constructor_get) {
  Use u;
  EXPECT_EQ(u.getNoun(), "");
  EXPECT_EQ(u.getPlayer(), nullptr);
}

TEST(UseTests, set_noun) {
  Use u;
  u.setNoun("Laser");
  EXPECT_EQ(u.getNoun(), "Laser");
}

TEST(UseTests, set_player) {
  Use u;
  Player* p = new Player();
  u.setPlayer(p);
  EXPECT_EQ(u.getPlayer(), p);
  delete p;
}

TEST(UseTests, execute_player_has_item) {
  Use u;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);
  p.setCurrentRoom(&r);

  u.setPlayer(&p);
  u.setNoun("box");
  EXPECT_EQ(u.execute(), "you can't use containers");
}

TEST(UseTests, execute_room_has_item) {
  Use u;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p.setCurrentRoom(&r);

  u.setPlayer(&p);
  u.setNoun("box");
  EXPECT_EQ(u.execute(), "you can't use containers");
}

TEST(UseTests, execute_inactive) {
  Use u;

  Player p;
  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  c->getState()->setActive(false);
  r.addEntity(c);
  p.setCurrentRoom(&r);

  u.setPlayer(&p);
  u.setNoun("box");
  EXPECT_EQ(u.execute(), "For some reason you can't");
}

TEST(UseTests, no_player) {
  Use u;
  EXPECT_THROW(u.execute(), unfinished_object_error);
}

TEST(UseTests, execute_no_item) {
  Use u;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  u.setPlayer(&p);
  u.setNoun("box");
  EXPECT_EQ(u.execute(), "There is no box");
}
