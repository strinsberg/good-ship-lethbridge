/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Item.h"
#include "Entity.h"
#include "EntitySpec.h"
#include "Event.h"
#include "Inform.h"
#include "Player.h"
#include "ObjectBlueprint.h"
#include <string>
#include "gtest/gtest.h"

TEST(ItemTests, constructor_get) {
  Item i;
  EXPECT_EQ("", i.getSpec()->getName());
  EXPECT_EQ(true, i.getState()->getActive());
  EXPECT_EQ("", i.getEvent()->getMessage());
}

TEST(ItemTests, set_spec) {
  Item i;
  EntitySpec* spec = new EntitySpec();
  spec->setName("steve");
  i.setSpec(spec);
  EXPECT_EQ("steve", i.getSpec()->getName());
}

TEST(ItemTests, set_state) {
  Item i;
  EntityState* state = new EntityState();
  state->setActive(true);
  i.setState(state);
  EXPECT_EQ(true, i.getState()->getActive());
}

TEST(ItemTests, set_use_event) {
  Item i;

  Event* e = new Inform();
  e->setMessage("HAHAHAHAHA!");
  i.setEvent(e);

  Player* p = new Player();
  EXPECT_EQ("HAHAHAHAHA!", i.use(p));
  delete p;
}

TEST(ItemTests, describe) {
  Item i;
  EntitySpec* spec = new EntitySpec();
  spec->setDescription("wet dirt");
  i.setSpec(spec);
  EXPECT_EQ("wet dirt", i.describe());
}

TEST(ItemTests, DISABLED_make_blueprint) {}
