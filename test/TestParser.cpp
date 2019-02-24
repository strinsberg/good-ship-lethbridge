/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Parser.h"
#include "Command.h"
#include "BadInput.h"
#include "gtest/gtest.h"
#include <string>


TEST(ParserTests, constructor) {
  Parser p("get laser");
  EXPECT_EQ(p.getInput(), "get laser");
}

TEST(ParserTests, parse_bad_input) {
  Parser p("scubadive");
  Command* c = p.parse();
  EXPECT_EQ(c->execute(), "You can't scubadive!");
  delete c;  // parser does not own the pointer it returns
}
