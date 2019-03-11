/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Quit.h"
#include <string>
#include "gtest/gtest.h"

TEST(QuitTests, constructor_get) {
  Quit q;
  EXPECT_EQ("", q.getNoun());
  EXPECT_EQ(nullptr, q.getGame());
}

TEST(QuitTests, set_game) {
  Quit q;
  Game* g = new Game();
  q.setGame(g);
  EXPECT_EQ(g, q.getGame());
}

TEST(QuitTests, execute) {
  Quit q;

  Game* g = new Game();
  q.setGame(g);
  EXPECT_EQ("Thanks for playing!", q.execute());
  EXPECT_EQ(false, g->isRunning());
}
