/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "GameData.h"
#include "gtest/gtest.h"
#include <string>


TEST(GameDataTests, constructor_and_getters) {
  GameData gd("{type:room, name=Captains Quaters,}");
  EXPECT_EQ(gd.getBegin(), 0);
  EXPECT_EQ(gd.getEnd(), 0);
  EXPECT_EQ(gd.getData(), "{type:room, name=Captains Quaters,}");
}

TEST(GameDataTests, get_next_object) {
  GameData gd("{type:room, name=Captains Quaters,}");
  EXPECT_EQ(gd.nextObject(), "{type:room, name=Captains Quaters,}");
  EXPECT_EQ(gd.nextObject(), GameData::eof);
}
