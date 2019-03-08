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
  Player* p;  // Allows simple check for set without player being implemented
  i.setPlayer(p);
  EXPECT_EQ(i.getPlayer(), p);
}

TEST(InventoryTests, DISABLED_execute_have_items) {
  Inventory i;
  // Create a player
  // create a couple items
  // add them to the players inventory
  // run i.execute and compare
  EXPECT_EQ(i.execute(), "You are carrying:\nobject1\nobject2");
}

TEST(InventoryTests, DISABLED_execute_no_items) {
  Inventory i;
  // Create a player
  // run i.execute and compare
  EXPECT_EQ(i.execute(), "You don't have anything!");
}
