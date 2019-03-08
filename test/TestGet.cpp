/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Get.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(GetTests, constructor_get) {
  Get g;
  EXPECT_EQ(g.getNoun(), "");
  EXPECT_EQ(g.getPlayer(), nullptr);
}

TEST(GetTests, set_noun) {
  Get g;
  g.setNoun("Laser");
  EXPECT_EQ(g.getNoun(), "Laser");
}

TEST(GetTests, set_player) {
  Get g;
  Player* p;  // Allows simple check for set without player being implemented
  g.setPlayer(p);
  EXPECT_EQ(g.getPlayer(), p);
}

TEST(GetTests, DISABLED_execute_item_exists) {
  Get g;
  // Create a player, room, and item entity
  // Add the item to the room
  // Set the players current_room to room
  // add the player and the name of the item to the get action
  // run get.execute and see the result
  EXPECT_EQ(g.execute(), "You take the object_name");
}

TEST(GetTests, DISABLED_execute_item_does_not_exist) {
  Get g;
  // Create a player, room
  // run get.execute and see the result
  EXPECT_EQ(g.execute(), "There is no object_name");
}
