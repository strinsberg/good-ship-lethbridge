/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Exit.h"
#include <sstream>
#include "gtest/gtest.h"

TEST(ExitTests, constructor_get) {
  Exit e;
  EXPECT_EQ(e.getNoun(), "");
  EXPECT_EQ(e.getPlayer(), nullptr);
}

TEST(ExitTests, set_noun) {
  Exit e;
  e.setNoun("Laser");
  EXPECT_EQ(e.getNoun(), "Laser");
}

TEST(ExitTests, set_player) {
  Exit e;
  Player* p;  // Allows simple check for set without player being implemented
  e.setPlayer(p);
  EXPECT_EQ(e.getPlayer(), p);
}

TEST(ExitTests, execute) {
  Exit e;
  EXPECT_EQ(e.execute(), "TBD");
}
