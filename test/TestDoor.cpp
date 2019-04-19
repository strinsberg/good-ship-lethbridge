/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Door.h"
#include "Room.h"
#include "Player.h"
#include "Entity.h"
#include "Entity.h"
#include "TransferItem.h"
#include "Inform.h"
#include <string>
#include "gtest/gtest.h"

TEST(DoorTests, constructor_get) {
  Door d;
  EXPECT_EQ("", d.getSpec()->getName());
  EXPECT_EQ(true, d.getState()->getActive());
}

TEST(DoorTests, set_destination) {
  Door d;
  Room* r = new Room();
  d.setDestination(r);
  EXPECT_EQ(r, d.getDestination());
  delete r;
}

TEST(DoorTests, set_here) {
  Door d;
  Room* r = new Room();
  d.setHere(r);
  EXPECT_EQ(r, d.getHere());
  delete r;
}

TEST(DoorTests, describe) {
  Door d;
  d.getSpec()->setDescription("a door to space");
  EXPECT_EQ("a door to space", d.describe());
}

TEST(DoorTests, use_normal) {
  Door d;

  Player* p = new Player("id123");
  Room* start = new Room("id456");
  Room* end = new Room("id789");

  Inform* i = new Inform("inf123", "You made it to the end");
  end->addEvent("enter", i);

  p->setCurrentRoom(start);
  d.setDestination(end);
  d.getSpec()->setName("rusty door");

  EXPECT_EQ("You use rusty door\nYou made it to the end", d.runEvent("use", p));
  EXPECT_EQ(end, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;
}

TEST(DoorTests, use_not_active) {
/*  Door d;

  Player* p = new Player();
  Room* start = new Room();
  Room* end = new Room();

  p->setCurrentRoom(start);
  d.setDestination(end);
  d.getState()->setActive(false);

  EXPECT_EQ("For some reason it doesn't work", d.use(p));
  EXPECT_EQ(start, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;*/
}

TEST(DoorTests, use_entity) {
/*  Door d;

  Entity* i = new Entity();
  i->getSpec()->setName("Calvin");

  Room* start = new Room();
  start->addEntity(i);
  Room* end = new Room();

  Inform* inf = new Inform();
  inf->setMessage("Calvin made it to the end");
  end->setEnter(inf);

  d.setHere(start);
  d.setDestination(end);
  d.getSpec()->setName("rusty door");

  EXPECT_EQ("Calvin uses rusty door\nCalvin made it to the end", d.use(i));
  EXPECT_EQ(nullptr, start->search("Calvin"));
  EXPECT_EQ(i, end->search("Calvin"));

  delete start;
  delete end;*/
}

TEST(DoorTests, use_no_destination) {
/*  Door d;

  Player* p = new Player();
  Room* start = new Room();

  p->setCurrentRoom(start);
  d.getSpec()->setName("rusty door");

  EXPECT_EQ("The door leads nowhere", d.use(p));
  EXPECT_EQ(start, p->getCurrentRoom());

  delete start;
  delete p;*/
}
