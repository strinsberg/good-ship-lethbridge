/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Room.h"
#include "Entity.h"
#include "Event.h"
#include "Inform.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "Exceptions.h"
#include "Entity.h"
#include <string>
#include "gtest/gtest.h"

TEST(RoomTests, constructor_get) {
  Room r;
  EXPECT_EQ("", r.getSpec()->getName());
  EXPECT_EQ(true, r.getState()->getObtainable());
}

TEST(RoomTests, enter) {
  Room r;

  Entity* ent;
  EXPECT_EQ("This place smells bad!", r.enter(ent));
}

TEST(RoomTests, enter_null) {
  Room r;
  Entity* ent;
  EXPECT_EQ("", r.enter(ent));
}

TEST(RoomTests, describe) {
  Room r;
  EntitySpec* spec = new EntitySpec();
  spec->setName("Captain's Room");
  spec->setDescription("It's your room!");
  r.setSpec(spec);

  EXPECT_EQ("Location: Captain's Room\n"
            "It's your room!", r.describe());
}
