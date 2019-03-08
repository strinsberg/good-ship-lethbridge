/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Use.h"
#include <string>
#include "gtest/gtest.h"

TEST(UseTests, constructor_get) {
  Use u;
  EXPECT_EQ(u.getNoun(), "");
  EXPECT_EQ(u.getPlayer(), nullptr);
}

TEST(UseTests, set_noun) {
  Use u;
  u.setNoun("Laser");
  EXPECT_EQ(u.getNoun(), "Laser");
}

TEST(UseTests, set_player) {
  Use u;
  Player* p;  // Allows simple check for set without player being implemented
  u.setPlayer(p);
  EXPECT_EQ(u.getPlayer(), p);
}

TEST(UseTests, execute_player_has_item) {
  Use u;
  // Create a player, room, and item
  // put item in player inventory, set player room to room
  // add player and item name to Use
  // run execute
  EXPECT_EQ(u.execute(), "Use description");
}

TEST(UseTests, execute_room_has_item) {
  Use u;
  // Create a player, room, and item
  // put item in room inventory, set player room to room
  // add player and item name to Use
  // run execute
  EXPECT_EQ(u.execute(), "Use description");
}

TEST(UseTests, execute_unusable) {
  Use u;
  // create player, and room
  // set player room
  // set player and item name to Use
  // run execute
  EXPECT_EQ(u.execute(), "You Can't use object_name!");
}

TEST(UseTests, execute_no_item) {
  Use u;
  // create player, and room
  // set player room
  // set player and item name to Use
  // run execute
  EXPECT_EQ(u.execute(), "There is no object_name!");
}
