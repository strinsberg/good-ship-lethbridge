/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Talk.h"
#include "Npc.h"
#include "Inform.h"
#include "Item.h"
#include <string>
#include "gtest/gtest.h"

TEST(TalkTests, constructor_get) {
  Player* p = new Player();
  Talk t(p);
  EXPECT_EQ(t.getNoun(), "");
  EXPECT_EQ(t.getPlayer(), p);
  delete p;
}

TEST(TalkTests, set_noun) {
  Player* p = new Player();
  Talk t(p);
  t.setNoun("Laser");
  EXPECT_EQ(t.getNoun(), "Laser");
  delete p;
}


TEST(TalkTests, execute_item_exists) {
  Player* p = new Player();
  Npc* npc = new Npc();
  npc->getSpec()->setName("ted");
  Room* room = new Room();
  room->addEntity(npc);
  p->setCurrentRoom(room);
  Inform* tell = new Inform();
  tell->setMessage("Hi, how are you?");
  npc->setEvent(tell);
  Talk talk(p);
  talk.setNoun("ted");

  EXPECT_EQ("Hi, how are you?", talk.execute());
  delete p;
  delete room;
}

TEST(TalkTests, execute_inactive) {
  Player* p = new Player();
  Npc* npc = new Npc();
  npc->getSpec()->setName("ted");
  npc->getState()->setActive(false);
  Room* room = new Room();
  room->addEntity(npc);
  p->setCurrentRoom(room);
  Inform* tell = new Inform();
  tell->setMessage("Hi, how are you?");
  npc->setEvent(tell);
  Talk talk(p);
  talk.setNoun("ted");

  EXPECT_EQ("ted can't talk right now", talk.execute());
  delete p;
  delete room;
}

TEST(TalkTests, execute_item_does_not_exist) {
  Player* p = new Player();
  Room* room = new Room();
  p->setCurrentRoom(room);
  Talk talk(p);
  talk.setNoun("ted");

  EXPECT_EQ("There is no ted", talk.execute());
  delete p;
  delete room;
}

TEST(TalkTests, execute_not_an_npc) {
  Player* p = new Player();

  Item* i = new Item();
  i->getSpec()->setName("box");
  i->getState()->setActive(false);

  Room* room = new Room();
  room->addEntity(i);
  p->setCurrentRoom(room);

  Inform* tell = new Inform();
  tell->setMessage("Hi, how are you?");
  i->setEvent(tell);
  Talk talk(p);
  talk.setNoun("box");

  EXPECT_EQ("You can't talk to box", talk.execute());
  delete p;
  delete room;

}
