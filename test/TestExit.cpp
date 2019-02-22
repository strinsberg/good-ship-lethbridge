/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Exit.h"
#include "gtest/gtest.h"
#include <sstream>


TEST(ExitActionTests, execute) {
  Exit e;
  std::stringstream ss;
  e.setOutput(&ss);
  e.setNoun("north");
  //e.setPlayer(???);
  e.execute();
  EXPECT_EQ(ss.str(), "you exit north");  // this output might need to change
}
