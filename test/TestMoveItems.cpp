/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-13
 */

#include "MoveItems.h"
#include "Event.h"
#include "Item.h"
#include "Container.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(MoveItemsTests, constructor_get) {
  Item* owner = new Item();
  MoveItems m(owner, "coin");
  EXPECT_EQ(owner, m.getOwner());
  EXPECT_EQ("coin", m.getItemName());
  EXPECT_EQ("", m.getMessage());
  EXPECT_EQ(false, m.getSpec()->isDone());
  delete owner;
}

TEST(MoveItemsTests, constructor_execute_give_to_player) {
  Item* item = new Item();
  item->getSpec()->setName("coin");
  Container* c = new Container();
  c->getSpec()->setName("Ted");
  c->addEntity(item);
  Player* p = new Player();

  MoveItems m(c, "coin");
  m.setGive(true);

  EXPECT_EQ("Ted gives you a coin", m.execute(p));
  EXPECT_EQ(item, p->search("coin"));
  EXPECT_EQ(nullptr, c->search("coin"));
  EXPECT_EQ(true, m.getSpec()->isDone());

  delete c;
  delete p;
}

TEST(MoveItemsTests, constructor_execute_take_from_player) {
  Item* item = new Item();
  item->getSpec()->setName("coin");
  Container* c = new Container();
  c->getSpec()->setName("Ted");
  Player* p = new Player();
  p->addEntity(item);

  MoveItems m(c, "coin");

  EXPECT_EQ("You give a coin to Ted", m.execute(p));
  EXPECT_EQ(nullptr, p->search("coin"));
  EXPECT_EQ(item, c->search("coin"));
  EXPECT_EQ(true, m.getSpec()->isDone());

  delete c;
  delete p;
}

TEST(MoveItemsTests, constructor_already_done) {
  Item* item = new Item();
  item->getSpec()->setName("coin");
  Container* c = new Container();
  c->getSpec()->setName("ted");
  Player* p = new Player();
  p->addEntity(item);

  MoveItems m(c, "coin");
  m.getSpec()->setDone(true);

  EXPECT_EQ("", m.execute(p));
  EXPECT_EQ(item, p->search("coin"));
  EXPECT_EQ(nullptr, c->search("coin"));
  EXPECT_EQ(true, m.getSpec()->isDone());

  delete c;
  delete p;
}
