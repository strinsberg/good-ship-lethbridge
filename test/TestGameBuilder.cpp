/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include "gtest/gtest.h"

// Add to tests as you know what you are doing in each room
TEST(GameBuilderTests, one_room_and_player) {
  Game* g = GameBuilder().newGame("Steve");
  Room* r = g->getRoom("Captain's Room");
  EXPECT_EQ("Captain's Room", r->getSpec()->getName());
  delete g;
}
