/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Exit.h"
#include <sstream>
#include "gtest/gtest.h"

TEST(ExitTests, constructor_get) {
  Exit e;
  EXPECT_EQ(e.getNoun(), "");
  EXPECT_EQ(e.getPlayer(), nullptr);
}

TEST(ExitTests, set_noun) {
  Exit e;
  e.setNoun("Laser");
  EXPECT_EQ(e.getNoun(), "Laser");
}

TEST(ExitTests, set_player) {
  Exit e;
  Player* p;  // Allows simple check for set without player being implemented
  e.setPlayer(p);
  EXPECT_EQ(e.getPlayer(), p);
}

TEST(ExitTests, DISABLED_execute_exit_exists) {
  Exit e;
  // create player, room, other room, exit
  // add exit to room
  // might need exit and enter events for the rooms
  // set player room
  // add player and exit name to the Exit
  EXPECT_EQ(e.execute(), "???");
}

TEST(ExitTests, DISABLED_execute_exit_is_not_active) {
  Exit e;
  // create player, room, other room, exit
  // add exit to room
  // set player room
  // add player and exit name to the Exit
  EXPECT_EQ(e.execute(), "You are unable to go that way");
}

TEST(ExitTests, DISABLED_execute_exit_does_not_exists) {
  Exit e;
  // create player, room
  // set player room
  // add player and exit name to Exit
  EXPECT_EQ(e.execute(), "There is no exit_name");
}
