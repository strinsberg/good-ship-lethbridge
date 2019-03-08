/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Get.h"
#include "Player.h"
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

TEST(GetTests, set_player) {
  Get g;
  Player* p;  // Allows simple check for set without player being implemented
  g.setPlayer(p);
  EXPECT_EQ(g.getPlayer(), p);
}
