/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Door.h"
#include "Room.h"
#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "ObjectBlueprint.h"
#include "Inform.h"
#include <string>
#include "gtest/gtest.h"

TEST(DoorTests, constructor_get) {
  Door d;
  EXPECT_EQ("", d.getSpec()->getName());
  EXPECT_EQ(true, d.getState()->getActive());
  EXPECT_EQ("", d.getEvent()->getMessage());
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

  Player* p = new Player();
  Room* start = new Room();
  Room* end = new Room();

  Inform* i = new Inform();
  i->setMessage("You made it to the end");
  end->setEnter(i);

  p->setCurrentRoom(start);
  d.setDestination(end);
  d.getSpec()->setName("rusty door");

  EXPECT_EQ("You use rusty door\nYou made it to the end", d.use(p));
  EXPECT_EQ(end, p->getCurrentRoom());

  delete start;
  delete end;
  delete p;
}

TEST(DoorTests, use_not_active) {
  Door d;

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
  delete p;
}

TEST(DoorTests, use_entity) {
  Door d;

  Entity* i = new Item();
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
  delete end;
}

TEST(DoorTests, use_no_destination) {
  Door d;

  Player* p = new Player();
  Room* start = new Room();

  p->setCurrentRoom(start);
  d.getSpec()->setName("rusty door");

  EXPECT_EQ("The door leads nowhere", d.use(p));
  EXPECT_EQ(start, p->getCurrentRoom());

  delete start;
  delete p;
}

TEST(DoorTests, make_blueprint) {
  Door d;
  ObjectBlueprint* bp = d.makeBlueprint();
  EXPECT_EQ("{\ntype=door,\nactive=true,\ndescription=,\ndestination=,\nhere=,"
            "\nhidden=false,\nname=,\nobtainable=true,\n}\n{\ntype=inform,"
            "\ndone=false,\nmessage=,\nname=,\nowner=,\n}", bp->toString());
  delete bp;
}
