/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "ObjectBlueprint.h"
#include "gtest/gtest.h"
#include <string>
#include <map>


TEST(ObjectBlueprintTests, constructor_get) {
  std::string
  data("{type=room, description=The captain's quarters, name=Captain's Quarters,}");
  ObjectBlueprint b(data);
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
