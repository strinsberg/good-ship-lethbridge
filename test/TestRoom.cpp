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
#include <string>
#include "gtest/gtest.h"

TEST(RoomTests, DISABLED_constructor_get) {
  Room r;
  EXPECT_EQ(r.getSpec(), nullptr);
  EXPECT_EQ(r.getState(), nullptr);
}

TEST(RoomTests, DISABLED_enter) {
  Room r;

  Event* e = new Inform();
  e->setMessage("This place smells bad!");
  r.setEnter(e);

  Entity* ent;
  EXPECT_EQ("This place smells bad!", r.enter(ent));
}

TEST(RoomTests, DISABLED_exit) {
  Room r;

  Event* e = new Inform();
  e->setMessage("This place smells bad!");
  r.setExit(e);

  Entity* ent;
  EXPECT_EQ("This place smells bad!", r.exit(ent));
}

TEST(RoomTests, DISABLED_use) {
  Room r;
  Entity* ent;
  EXPECT_EQ("You can't use a room!", r.use(ent));
}

TEST(RoomTests, DISABLED_describe) {
  Room r;
  EntitySpec* spec = new EntitySpec();
  spec->setName("Captain's Room");
  spec->setDescription("It's your room!");
  r.setSpec(spec);

  Entity* ent;
  EXPECT_EQ("Location: Captain's Room\n"
            "It's your room!", r.describe());
}

TEST(RoomTests, DISABLED_make_blueprint) {
  Room r;
  Entity* ent;
  EXPECT_EQ("You can't use a room!", r.use(ent));
}

