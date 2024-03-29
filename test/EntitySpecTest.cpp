/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "gtest/gtest.h"
#include "EntitySpec.h"
#include "Exceptions.h"


//this is the test for the constructor
TEST(TestEntitySpec, EntitySpec) {
  EntitySpec e;
  EXPECT_EQ("", e.getName());
  EXPECT_EQ("", e.getDescription());
}
//this test the matches function
TEST(TestEntitySpec, matches) {
  EntitySpec e;
  e.setName("max");
  EXPECT_TRUE(e.matches("max"));
}
TEST(TestEntitySpec, matches_fail) {
  EntitySpec e;
  e.setName("max");
  EXPECT_FALSE(e.matches("tim"));
}
//this test both set and get name
TEST(TestEntitySpec, getName) {
  EntitySpec e;
  e.setName("max");
  EXPECT_EQ("max", e.getName());
}
//this test both set and get descriptions
TEST(TestEntitySpec, getDescription) {
  EntitySpec e;
  e.setDescription("this is e");
  EXPECT_EQ("this is e", e.getDescription());
}
