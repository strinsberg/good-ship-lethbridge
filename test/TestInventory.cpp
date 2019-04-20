/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#include "Inventory.h"
#include <string>
#include "gtest/gtest.h"

TEST(InventoryTests, constructor_get) {
  Player* p = new Player();
  Inventory i(p);
  EXPECT_EQ(i.getNoun(), "");
  EXPECT_EQ(i.getPlayer(), p);
  delete p;
}

TEST(InventoryTests, set_noun) {
  Player* p = new Player();
  Inventory i(p);
  i.setNoun("Laser");
  EXPECT_EQ(i.getNoun(), "Laser");
  delete p;
}

TEST(InventoryTests, execute_item_in_inventory) {
  Player* p = new Player();
  Inventory i(p);

  Room r;
  p->setCurrentRoom(&r);

  Container* c = new Container("id123");
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);

  i.setNoun("");
  EXPECT_EQ("You have:\nbox -> a box", i.execute());
  delete p;
}

TEST(InventoryTests, execute_multiple_items_in_inventory) {
  Player* p = new Player();
  Inventory i(p);

  Room r;
  p->setCurrentRoom(&r);

  Container* c = new Container("id123");
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);

  Container* c2 = new Container("id456");
  c2->getSpec()->setName("gold");
  c2->getSpec()->setDescription("a shiny coin");
  p->addEntity(c2);

  i.setNoun("");
  EXPECT_EQ("You have:\nbox -> a box\ngold -> a shiny coin", i.execute());
  delete p;
}

TEST(InventoryTests, execute_no_items) {
  Player* p = new Player();
  Inventory i(p);

  Room r;
  p->setCurrentRoom(&r);

  i.setNoun("");
  EXPECT_EQ("You don't have anything!", i.execute());
  delete p;
}

TEST(InventoryTests, execute_search_item_in_inventory) {
  Player* p = new Player();
  Inventory i(p);

  Room r;
  p->setCurrentRoom(&r);

  Container* c = new Container("id123");
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);

  i.setNoun("box");
  EXPECT_EQ("You have that", i.execute());
  delete p;
}

TEST(InventoryTests, execute_search_item_not_in_inventory) {
  Player* p = new Player();
  Inventory i(p);

  Room r;
  p->setCurrentRoom(&r);

  Container* c = new Container("id123");
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p->addEntity(c);

  i.setNoun("gold");
  EXPECT_EQ("You don't have that", i.execute());
  delete p;
}

