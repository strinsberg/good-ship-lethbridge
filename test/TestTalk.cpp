/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Talk.h"
#include <string>
#include "gtest/gtest.h"

TEST(TalkTests, constructor_get) {
  Talk t;
  EXPECT_EQ(t.getNoun(), "");
  EXPECT_EQ(t.getPlayer(), nullptr);
}

TEST(TalkTests, set_noun) {
  Talk t;
  t.setNoun("Laser");
  EXPECT_EQ(t.getNoun(), "Laser");
}

TEST(TalkTests, set_player) {
  Talk t;
  Player* p = new Player();
  t.setPlayer(p);
  EXPECT_EQ(t.getPlayer(), p);
  delete p;
}

TEST(TalkTests, DISABLED_execute_item_exists) {
  Talk t;
  // Create a player, room, and item entity
  // Add the item to the room
  // Set the players current_room to room
  // add the player and the name of the item to the get action
  // run get.execute and see the result
  // Test the simplest conversation
  EXPECT_EQ(t.execute(), "Conversation");
}

TEST(TalkTests, DISABLED_execute_does_not_talk) {
  Talk t;
  // Create player, room, and entity
  // add entity to room
  // set player room
  // add player and entity name to talk
  // run execute
  EXPECT_EQ(t.execute(), "You get no response");
}

TEST(TalkTests, DISABLED_execute_item_does_not_exist) {
  Talk t;
  // Create a player, room
  // run get.execute and see the result
  EXPECT_EQ(t.execute(), "There is no object_name");
}
