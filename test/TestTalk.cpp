/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Talk.h"
#include <string>
#include "gtest/gtest.h"

TEST(TalkTests, constructor_get) {
  Talk t;
  EXPECT_EQ(t.getNoun(), "");
  EXPECT_EQ(t.getPlayer(), nullptr);
}

TEST(TalkTests, set_noun) {
  Talk t;
  t.setNoun("Laser");
  EXPECT_EQ(t.getNoun(), "Laser");
}

TEST(TalkTests, set_player) {
  Talk t;
  Player* p;  // Allows simple check for set without player being implemented
  t.setPlayer(p);
  EXPECT_EQ(t.getPlayer(), p);
}

