/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Drop.h"
#include <string>
#include "gtest/gtest.h"

TEST(DropTests, constructor_get) {
  Drop d;
  EXPECT_EQ(d.getNoun(), "");
  EXPECT_EQ(d.getPlayer(), nullptr);
}

TEST(DropTests, set_noun) {
  Drop d;
  d.setNoun("Laser");
  EXPECT_EQ(d.getNoun(), "Laser");
}
