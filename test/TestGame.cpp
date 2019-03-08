/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Game.h"
#include "Player.h"
#include <iostream>
#include <sstream>
#include "gtest/gtest.h"


TEST(GameTests, constructor) {
  Game g;
  EXPECT_EQ(g.getPlayer(), nullptr);
  EXPECT_EQ(g.numRooms(), 0);
}

TEST(GameTests, get_set_player) {
  Game g;
  Player* p;// = new Player();  // add when these are done
  g.setPlayer(p);
  EXPECT_EQ(g.getPlayer(), p);
}

TEST(GameTests, get_add_room) {
  Game g;
  Room* r;// = new Room();
  g.addRoom("Captains Quaters", r);
  EXPECT_EQ(g.getRoom("Captains Quaters"), r);
  EXPECT_EQ(g.numRooms(), 1);
}

TEST(GameTests, DISABLED_get_room_not_there) {}

TEST(GameTests, DISABLED_add_room_throws) {}

TEST(GameTests, DISABLED_run) {}

