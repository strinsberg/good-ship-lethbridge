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
