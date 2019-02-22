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

/*class FakePlayer : public Player {
public:
  FakePlayer(std::ostream* o) {setOutput(o);}
  void describe() {*out << "test";}
};
*/
TEST(GameTests, constructor) {
  Game g;
  EXPECT_EQ(g.getPlayer(), nullptr);
  EXPECT_EQ(g.numRooms(), 0);
}

TEST(GameTests, get_set_player) {
  /*
  Game g;
  std::stringstream ss;
  FakePlayer p(&ss);
  g.getPlayer()->describe();
  EXPECT_EQ(ss.str(), "test");*/
  FAIL();
}

TEST(GameTests, get_room) {
  FAIL();
}

TEST(GameTests, add_room) {
  FAIL();
}

TEST(GameTests, add_room_throws) {
  FAIL();
}

