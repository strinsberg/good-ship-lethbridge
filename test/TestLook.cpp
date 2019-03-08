/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include <string>
#include "gtest/gtest.h"

TEST(LookTests, constructor_get) {
  Look l;
  EXPECT_EQ(l.getNoun(), "");
  EXPECT_EQ(l.getPlayer(), nullptr);
}

TEST(LookTests, set_noun) {
  Look l;
  l.setNoun("Laser");
  EXPECT_EQ(l.getNoun(), "Laser");
}
