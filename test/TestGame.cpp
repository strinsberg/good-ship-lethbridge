/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Game.h"
#include "Player.h"
#include "Exceptions.h"
#include <iostream>
#include <sstream>
#include "gtest/gtest.h"


TEST(GameTests, constructor) {
  Game g;
  EXPECT_EQ("None", g.getPlayer()->getSpec()->getName());
  EXPECT_EQ(0, g.numRooms());
}

TEST(GameTests, get_set_player) {
  Game g;
  Player* p = new Player();
  g.setPlayer(p);
  EXPECT_EQ(g.getPlayer(), p);
}

TEST(GameTests, get_add_room) {
  Game g;
  Room* r = new Room();
  g.addRoom("Captains Quaters", r);
  EXPECT_EQ(g.getRoom("Captains Quaters"), r);
  EXPECT_EQ(g.numRooms(), 1);
}

TEST(GameTests, get_room_not_there) {
  Game g;
  EXPECT_EQ(nullptr, g.getRoom("Any"));
}

TEST(GameTests, add_room_throws) {
  Game g;
  Room* r = new Room();
  g.addRoom("Captains Quaters", r);
  EXPECT_EQ(g.getRoom("Captains Quaters"), r);

  Room* r2 = new Room();
  EXPECT_THROW(g.addRoom("Captains Quaters", r2), invalid_parameter_error);
  delete r2;
}

TEST(GameTests, run) {
  std::stringstream in, out;
  in << "get box\nquit";
  Game g(in, out);
  g.run();
  EXPECT_EQ("> You can't get!\n> Thanks for playing!\n", out.str());
}

