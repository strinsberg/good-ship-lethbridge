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

TEST(GameBuilderTests, start_in_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  EXPECT_EQ(g->getRoom("rmcapt"), p->getCurrentRoom());
  delete g;
}

TEST(GameBuilderTests, door_in_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  Room* r = g->getRoom("rmcapt");
  EXPECT_EQ("common room door", r->searchById("drcaptcom")->getSpec()->getName());
  delete g;
}

TEST(GameBuilderTests, container_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  Room* r = g->getRoom("rmcapt");
  EXPECT_EQ("box", r->searchById("captbox")->getSpec()->getName());
  delete g;
}

TEST(GameBuilderTests, entity_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  Room* r = g->getRoom("rmcapt");
  EXPECT_EQ("bed", r->searchById("captbed")->getSpec()->getName());
  delete g;
}

TEST(GameBuilderTests, npc_hall) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  Room* r = g->getRoom("rmhall1");
  EXPECT_EQ("barbara mcdougal", r->searchById("bmcdoug")->getSpec()->getName());
  delete g;
}

TEST(GameBuilderTests, event_room1) {
  GameBuilder gb;
  Game* g = gb.newGame("steve");
  Player* p = g->getPlayer();
  Room* r = g->getRoom("rmcapt");
  Entity* e = r->searchById("captwin");
  EXPECT_EQ("you see endless space. a small cloud of debris is floating neaby.", e->runEvent("look", p));
  delete g;
}
