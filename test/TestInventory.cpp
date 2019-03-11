/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Inventory.h"
#include <string>
#include "gtest/gtest.h"

TEST(InventoryTests, constructor_get) {
  Inventory i;
  EXPECT_EQ(i.getNoun(), "");
  EXPECT_EQ(i.getPlayer(), nullptr);
}

TEST(InventoryTests, set_noun) {
  Inventory i;
  i.setNoun("Laser");
  EXPECT_EQ(i.getNoun(), "Laser");
}

TEST(InventoryTests, set_player) {
  Inventory i;
  Player* p;
  i.setPlayer(p);
  EXPECT_EQ(i.getPlayer(), p);
}

TEST(InventoryTests, execute_item_in_inventory) {
  Inventory i;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);

  i.setPlayer(&p);
  i.setNoun("");
  EXPECT_EQ("You have:\nbox -> a box", i.execute());
}

TEST(InventoryTests, execute_multiple_items_in_inventory) {
  Inventory i;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);

  Container* c2 = new Container();
  c2->getSpec()->setName("gold");
  c2->getSpec()->setDescription("a shiny coin");
  p.addEntity(c2);

  i.setPlayer(&p);
  i.setNoun("");
  EXPECT_EQ("You have:\nbox -> a box\ngold -> a shiny coin", i.execute());
}

TEST(InventoryTests, execute_no_items) {
  Inventory i;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  i.setPlayer(&p);
  i.setNoun("");
  EXPECT_EQ("You don't have anything!", i.execute());
}

TEST(InventoryTests, execute_search_item_in_inventory) {
  Inventory i;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);

  i.setPlayer(&p);
  i.setNoun("box");
  EXPECT_EQ("You have that", i.execute());
}

TEST(InventoryTests, execute_search_item_not_in_inventory) {
  Inventory i;

  Player p;
  Room r;
  p.setCurrentRoom(&r);

  Container* c = new Container();
  c->getSpec()->setName("box");
  c->getSpec()->setDescription("a box");
  p.addEntity(c);

  i.setPlayer(&p);
  i.setNoun("gold");
  EXPECT_EQ("You don't have that", i.execute());
}

