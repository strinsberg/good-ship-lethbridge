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
#include "Entity.h"
#include <string>
#include "gtest/gtest.h"

TEST(UseTests, constructor_get) {
  Player* p = new Player();
  Use u(p);
  EXPECT_EQ(u.getNoun(), "");
  EXPECT_EQ(u.getPlayer(), p);
  delete p;
}

TEST(UseTests, set_noun) {
  Player* p = new Player();
  Use u(p);
  u.setNoun("Laser");
  EXPECT_EQ(u.getNoun(), "Laser");
  delete p;
}

TEST(UseTests, DISABLED_execute_player_has_item) {
  Player* p = new Player();
  Use u(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);
  p->setCurrentRoom(&r);

  u.setNoun("box");
  EXPECT_EQ(u.execute(), "you can't use containers");
  delete p;
}

TEST(UseTests, DISABLED_execute_room_has_item) {
  Player* p = new Player();
  Use u(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  r.addEntity(c);
  p->setCurrentRoom(&r);

  u.setNoun("box");
  EXPECT_EQ(u.execute(), "you can't use containers");
  delete p;
}

TEST(UseTests, DISABLED_execute_inactive) {
  Player* p = new Player();
  Use u(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  c->getState()->setActive(false);
  r.addEntity(c);
  p->setCurrentRoom(&r);

  u.setNoun("box");
  EXPECT_EQ(u.execute(), "For some reason you can't");
  delete p;
}

TEST(UseTests, DISABLED_execute_no_item) {
  Player* p = new Player();
  Use u(p);

  Room r;
  p->setCurrentRoom(&r);

  u.setNoun("box");
  EXPECT_EQ(u.execute(), "There is no box");
  delete p;
}

TEST(UseTests, DISABLED_execute_inactive_locked) {
/*  Player* p = new Player();
  Use u(p);

  Room r;
  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  c->getState()->setActive(false);
  r.addEntity(c);
  p->setCurrentRoom(&r);

  Entity* item = new Entity();
  p->addEntity(item);

  KeyLock* lock = new KeyLock(c, item);
  lock->setMessage("You can now open the box!");
  c->setEvent(lock);

  u.setNoun("box");
  EXPECT_EQ(u.execute(), "You can now open the box!");
  EXPECT_EQ(true, c->getState()->getActive());
  delete p;*/
}

TEST(UseTests, execute_no_player) {
  Player* p = nullptr;
  Use u(p);
  EXPECT_THROW(u.execute(), unfinished_object_error);
}
