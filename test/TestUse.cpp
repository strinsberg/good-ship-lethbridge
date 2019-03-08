/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Use.h"
#include <string>
#include "gtest/gtest.h"

TEST(UseTests, constructor_get) {
  Use u;
  EXPECT_EQ(u.getNoun(), "");
  EXPECT_EQ(u.getPlayer(), nullptr);
}

TEST(UseTests, set_noun) {
  Use u;
  u.setNoun("Laser");
  EXPECT_EQ(u.getNoun(), "Laser");
}

TEST(UseTests, set_player) {
  Use u;
  Player* p;  // Allows simple check for set without player being implemented
  u.setPlayer(p);
  EXPECT_EQ(u.getPlayer(), p);
}

TEST(UseTests, execute) {
  Use u;
  EXPECT_EQ(u.execute(), "TBD");
}
