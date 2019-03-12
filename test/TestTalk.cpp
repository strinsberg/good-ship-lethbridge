/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Talk.h"
#include <string>
#include "gtest/gtest.h"

TEST(TalkTests, constructor_get) {
  Player* p = new Player();
  Talk t(p);
  EXPECT_EQ(t.getNoun(), "");
  EXPECT_EQ(t.getPlayer(), p);
  delete p;
}

TEST(TalkTests, set_noun) {
  Player* p = new Player();
  Talk t(p);
  t.setNoun("Laser");
  EXPECT_EQ(t.getNoun(), "Laser");
  delete p;
}


TEST(TalkTests, DISABLED_execute_item_exists) {

}

TEST(TalkTests, DISABLED_execute_does_not_talk) {

}

TEST(TalkTests, DISABLED_execute_item_does_not_exist) {

}
