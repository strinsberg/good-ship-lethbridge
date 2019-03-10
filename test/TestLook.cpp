/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include <string>
#include "gtest/gtest.h"

TEST(LookTests, constructor_get) {
  Look l;
  EXPECT_EQ(l.getNoun(), "");
  EXPECT_EQ(l.getPlayer(), nullptr);
}

TEST(LookTests, set_noun) {
  Look l;
  l.setNoun("Laser");
  EXPECT_EQ(l.getNoun(), "Laser");
}

TEST(LookTests, set_player) {
  Look l;
  Player* p;  // Allows simple check for set without player being implemented
  l.setPlayer(p);
  EXPECT_EQ(l.getPlayer(), p);
}

TEST(LookTests, DISABLED_execute_player_has_item) {
  Look l;
  // Create a player, room, and item
  // put item in player inventory, set player room to room
  // add player and item name to look
  // run execute
  EXPECT_EQ(l.execute(), "Item description");
}

TEST(LookTests, DISABLED_execute_room_has_item) {
  Look l;
  // Create a player, room, and item
  // put item in room inventory, set player room to room
  // add player and item name to look
  // run execute
  EXPECT_EQ(l.execute(), "Item Description");
}

TEST(LookTests, DISABLED_execute_no_item) {
  Look l;
  // create player, and room
  // set player room
  // set player and item name to look
  // run execute
  EXPECT_EQ(l.execute(), "There is no object_name!");
}
