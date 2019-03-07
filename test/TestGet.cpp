/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Get.h"
#include <string>
#include "gtest/gtest.h"

TEST(GetTests, constructor_get) {
  Get g;
  EXPECT_EQ(g.getNoun(), "");
  EXPECT_EQ(g.getPlayer(), nullptr);
}

TEST(GetTests, set_noun) {
  Get g;
  g.setNoun("Laser");
  EXPECT_EQ(g.getNoun(), "Laser");
}
