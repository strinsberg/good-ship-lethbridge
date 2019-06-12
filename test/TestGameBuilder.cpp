/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11, 2019-04-21
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "gtest/gtest.h"

// All these tests run based on the default gameData
// If the game data is changed for the first couple rooms
// The tests will need to be altered.
TEST(GameBuilderTests, newGame) {
    GameBuilder g;
    Game* game = g.newGame("Test");
    // Add some actual tests here
    delete game;
}
