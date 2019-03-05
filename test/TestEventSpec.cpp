/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "EventSpec.h"
#include "gtest/gtest.h"
#include <string>


TEST(EventSpecTests, constructor_get) {
  EventSpec s;
  EXPECT_EQ(s.isDone(), false);
  EXPECT_EQ(s.getName(), "");
}

TEST(EventSpecTests, set_done) {
  EventSpec s;
  s.setDone(true);
  EXPECT_EQ(s.isDone(), true);
}

TEST(EventSpecTests, set_name) {
  EventSpec s;
  std::string name("no_use");
  s.setName(name);
  EXPECT_EQ(s.getName(), "no_use");
}
