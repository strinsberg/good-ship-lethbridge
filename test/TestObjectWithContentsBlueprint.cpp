/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "ObjectWithContentsBlueprint.h"
#include "ObjectBlueprint.h"
#include <string>
#include <vector>
#include <sstream>
#include "gtest/gtest.h"


TEST(ObjectWithContentsBlueprintTests, constructor_get) {
  std::string data("{type=room, description=The captain's "
                   "quarters, name=Captain's Quarters,}");
  ObjectWithContentsBlueprint b(data);
  EXPECT_EQ(b.getType(), "room");
  EXPECT_EQ(b.getField("description"), "The captain's quarters");
  EXPECT_EQ(b.getField("name"), "Captain's Quarters");
}

TEST(ObjectWithContentsBlueprintTests, add_blueprint_and_iterators) {
  ObjectWithContentsBlueprint b;
  ObjectBlueprint* o = new ObjectBlueprint();
  b.addBlueprint(o);
  EXPECT_EQ(b.begin() + 1, b.end());
}

TEST(ObjectWithContentsBlueprintTests, to_string) {
  ObjectWithContentsBlueprint b("{type=room, name=Captain's Quarters,}");

  ObjectBlueprint* o =
    new ObjectBlueprint("{type=fuse, name=Door fuse,}");
  b.addBlueprint(o);

  ObjectBlueprint* o2 =
    new ObjectBlueprint("{type=car, name=Sweet Ride,}");
  b.addBlueprint(o2);

  EXPECT_EQ(b.begin() + 2, b.end());
  EXPECT_EQ(b.toString(),
            "{\ntype=room,\nname=Captain's Quarters,\n}\n"
            "{\ntype=fuse,\nname=Door fuse,\n}\n"
            "{\ntype=car,\nname=Sweet Ride,\n}");
}
