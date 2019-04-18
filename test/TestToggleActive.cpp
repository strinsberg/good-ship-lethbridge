/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "ToggleActive.h"
#include "Player.h"
#include "gtest/gtest.h"

TEST(ToggleActiveEventTests, normal) {
  Player* p = new Player();
  ToggleActive tog("toggle123", p);
  EXPECT_EQ("", tog.execute(p));
  EXPECT_FALSE(p->getState()->getActive());
  delete p;
}
