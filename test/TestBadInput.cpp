/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

 #include "BadInput.h"
 #include "Command.h"
#include "gtest/gtest.h"
#include <string>


TEST(BadInputTests, construct) {
  BadInput b;
  EXPECT_EQ(b.getNoun(), "");
}

TEST(BadInputTests, execute) {
  BadInput b;
  b.setNoun("fly");
  EXPECT_EQ(b.getNoun(), "fly");
  EXPECT_EQ(b.execute(), "You can't fly!");
}
