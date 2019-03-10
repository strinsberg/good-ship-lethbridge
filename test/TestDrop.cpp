/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Drop.h"
#include <string>
#include "gtest/gtest.h"

TEST(DropTests, constructor_get) {
  Drop d;
  EXPECT_EQ(d.getNoun(), "");
  EXPECT_EQ(d.getPlayer(), nullptr);
}

TEST(DropTests, set_noun) {
  Drop d;
  d.setNoun("Laser");
  EXPECT_EQ(d.getNoun(), "Laser");
}

TEST(DropTests, set_player) {
  Drop d;
  Player* p;  // Allows simple check for set without player being implemented
  d.setPlayer(p);
  EXPECT_EQ(d.getPlayer(), p);
}

TEST(DropTests, DISABLED_execute_item_exists) {
  Drop d;
  // Create a player, room, and item entity
  // Add the item to the player
  // Set the players current_room to room
  // add the player and the name of the item to the get action
  // run get.execute and see the result
  EXPECT_EQ(d.execute(), "You drop the object_name");
}

TEST(DropTests, DISABLED_execute_item_does_not_exits) {
  Drop d;
  // Create a player
  // run get.execute and see the result
  EXPECT_EQ(d.execute(), "You don't have object_name");
}
