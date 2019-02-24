/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Game.h"
#include "Player.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>


TEST(GameTests, constructor) {
  Game g;
  EXPECT_EQ(g.getPlayer(), nullptr);
  EXPECT_EQ(g.numRooms(), 0);
}

// Some tests will need to have nullptr replaced with actual instances when those classes are implemented
// as nullptr is not really a good test value. ie if a room is not in the game it will return nullptr.
TEST(GameTests, get_set_player) {
  Game g;
  Player* p = nullptr;
  g.setPlayer(p);
  EXPECT_EQ(g.getPlayer(), p);
}

TEST(GameTests, get_add_room) {
  Game g;
  Room* r = nullptr;
  g.addRoom("Captains Quaters", r);
  EXPECT_EQ(g.getRoom("Captains Quaters"), r);
  EXPECT_EQ(g.numRooms(), 1);
}

TEST(GameTests, DISABLED_get_room_not_there) {

}

TEST(GameTests, DISABLED_add_room_throws) {

}

// This will require a very simple senario for the game run procedure to be set up
// maybe even some mock objects once this is possible
TEST(GameTests, DISABLED_run) {

}

