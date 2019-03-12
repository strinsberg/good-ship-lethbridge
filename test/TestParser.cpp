/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Parser.h"
#include "Command.h"
#include "BadInput.h"
#include "Game.h"
#include <string>
#include "gtest/gtest.h"


TEST(ParserTests, constructor) {
  Game g;
  Parser p("get laser", &g);
  EXPECT_EQ("get laser", p.getInput());
}

TEST(ParserTests, parse_bad_input) {
  Game g;
  Parser p("scubadive", &g);
  Command* c = p.parse();
  EXPECT_EQ("You can't scubadive!", c->execute());
  delete c;  // parser does not own the pointer it returns
}

TEST(ParserTests, parse_quit) {
  Game g;
  Parser p("quit", &g);
  Command* c = p.parse();
  EXPECT_EQ("Thanks for playing!", c->execute());
  EXPECT_EQ(false, g.isRunning());
  delete c;  // parser does not own the pointer it returns
}
