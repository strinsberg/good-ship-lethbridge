/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "GameData.h"
#include <string>
#include "gtest/gtest.h"


TEST(GameDataTests, get_next_object) {
  GameData gd(
    "{type=room, name=Captains Quaters,} {type=door, name=Broken Door,}");
  EXPECT_EQ(gd.nextObject(), "{type=room, name=Captains Quaters,}");
  EXPECT_EQ(gd.nextObject(), "{type=door, name=Broken Door,}");
  EXPECT_EQ(gd.nextObject(), GameData::eof());
}
