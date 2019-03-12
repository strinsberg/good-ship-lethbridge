/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Exit.h"
#include <sstream>
#include "gtest/gtest.h"

TEST(ExitTests, constructor_get) {
  Player* p = new Player();
  Exit e(p);
  EXPECT_EQ(e.getNoun(), "");
  EXPECT_EQ(e.getPlayer(), p);
  delete p;
}

TEST(ExitTests, set_noun) {
  Player* p = new Player();
  Exit e(p);
  e.setNoun("Laser");
  EXPECT_EQ(e.getNoun(), "Laser");
  delete p;
}

TEST(ExitTests, DISABLED_execute_exit_exists) {

}

TEST(ExitTests, DISABLED_execute_exit_is_not_active) {

}

TEST(ExitTests, DISABLED_execute_exit_does_not_exists) {

}
