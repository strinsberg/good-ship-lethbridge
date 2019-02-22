/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Game.h"
#include "gtest/gtest.h"


TEST(GameTests, constructor) {
  Game g;
  EXPECT_EQ(g.getPlayer(), nullptr);
  EXPECT_EQ(g.numRooms(), 0);
}

TEST(GameTests, get_set_player) {
  Game g;
  FAIL();
}

TEST(GameTests, get_room) {
  FAIL();
}

TEST(GameTests, add_room) {
  FAIL();
}
