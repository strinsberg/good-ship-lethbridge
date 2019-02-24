/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "ObjectBlueprint.h"
#include "gtest/gtest.h"
#include <string>
#include <map>


TEST(ObjectBlueprintTests, DISABLED_constructor_get) {
  ObjectBlueprint b("{type=room, description=The captian's quarters, name=Captain's Quarters,}");
  EXPECT_EQ(b.getType(), "room");
  EXPECT_EQ(b.getField("description"), "The captain's quarters");
  EXPECT_EQ(b.getField("name"), "Captain's Quarters");
}

TEST(ObjectBlueprintTests, set_field) {
  ObjectBlueprint b;
  b.setField("type", "room");
  EXPECT_EQ(b.getType(), "room");
  b.setField("name", "Captain's Quarters");
  EXPECT_EQ(b.getField("name"), "Captain's Quarters");
}

TEST(ObjectBlueprintTests, toString) {
    ObjectBlueprint b;
  b.setField("type", "room");
  b.setField("name", "Captain's Quarters");
  EXPECT_EQ(b.toString(), "{\ntype=room,\nname=Captain's Quarters,\n}");
}
