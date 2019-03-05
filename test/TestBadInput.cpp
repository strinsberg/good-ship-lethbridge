/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "BadInput.h"
#include "Command.h"
#include <string>
#include "gtest/gtest.h"


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
