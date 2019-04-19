/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Exit.h"
#include "Door.h"
#include "Room.h"
#include "Inform.h"
#include "Entity.h"
#include <sstream>
#include "gtest/gtest.h"

TEST(ExitTests, constructor_get) {
  Player* p = new Player();
  Exit e(p);
  EXPECT_EQ(e.getNoun(), "");
  EXPECT_EQ(e.getPlayer(), p);
  delete p;
}

TEST(ExitTests, set_noun) {
  Player* p = new Player();
  Exit e(p);
  e.setNoun("Laser");
  EXPECT_EQ(e.getNoun(), "Laser");
  delete p;
}

TEST(ExitTests, execute_exit_exists) {
/*  Room* start = new Room();
  Room* end = new Room();
  Inform* enter = new Inform();
  enter->setMessage("You are now in the end room");
  end->setEnter(enter);
  Door* toEnd = new Door();
  toEnd->getSpec()->setName("next");
  toEnd->setHere(start);
  toEnd->setDestination(end);
  start->addEntity(toEnd);

  Player* p = new Player();
  p->setCurrentRoom(start);

  Exit e(p);
  e.setNoun("next");

  EXPECT_EQ("You are now in the end room", e.execute());
  EXPECT_EQ(end, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;
}

TEST(ExitTests, execute_exit_is_not_active) {
  Room* start = new Room();
  Room* end = new Room();
  Door* toEnd = new Door();
  toEnd->getState()->setActive(false);
  toEnd->getSpec()->setName("next");
  toEnd->setHere(start);
  toEnd->setDestination(end);
  start->addEntity(toEnd);

  Player* p = new Player();
  p->setCurrentRoom(start);

  Exit e(p);
  e.setNoun("next");

  EXPECT_EQ("For some reason you can't", e.execute());
  EXPECT_EQ(start, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;
}

TEST(ExitTests, execute_exit_does_not_exists) {
  Room* start = new Room();
  Room* end = new Room();
  Door* toEnd = new Door();
  toEnd->getState()->setActive(false);
  toEnd->getSpec()->setName("prev");
  toEnd->setHere(start);
  toEnd->setDestination(end);
  start->addEntity(toEnd);

  Player* p = new Player();
  p->setCurrentRoom(start);

  Exit e(p);
  e.setNoun("next");

  EXPECT_EQ("There is no exit next", e.execute());
  EXPECT_EQ(start, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;
}

TEST(ExitTests, execute_not_an_exit) {
  Room* start = new Room();
  Room* end = new Room();
  Entity* i = new Entity();
  i->getSpec()->setName("box");
  start->addEntity(i);

  Player* p = new Player();
  p->setCurrentRoom(start);

  Exit e(p);
  e.setNoun("box");

  EXPECT_EQ("box is not an exit!", e.execute());
  EXPECT_EQ(start, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;
}
