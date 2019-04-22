/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "gtest/gtest.h"

// All these tests run based on the default gameData
// If the game data is changed for the first couple rooms
// The tests will need to be altered.

TEST(GameBuilderTests, start_in_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  EXPECT_EQ(g->getRoom("r1"), p->getCurrentRoom());
}

TEST(GameBuilderTests, door_in_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  Room* r = g->getRoom("r1");
  EXPECT_EQ("common room door", r->searchById("r1r2")->getSpec()->getName());
}
