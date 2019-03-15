/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-10
 */

#include "Player.h"
#include "Room.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include <string>
#include "gtest/gtest.h"
#include "Suit.h"

TEST(PlayerTests, constructor_get) {
  Player p;
  EXPECT_EQ(nullptr, p.getCurrentRoom());
}

TEST(PlayerTests, set_room) {
  Player p;

  Room* r = new Room();
  p.setCurrentRoom(r);

  EXPECT_EQ(r, p.getCurrentRoom());
  delete r;
}

TEST(PlayerTests, describe) {
  Player p;

  EntitySpec* spec = new EntitySpec();
  spec->setDescription("That's You!");
  p.setSpec(spec);

  EXPECT_EQ("That's You!", p.describe());
}

TEST(PlayerTests, use) {
  Player p;
  Entity* ent;
  EXPECT_EQ("Have some self respect! Don't use yourself!", p.use(ent));
}

TEST(PlayerTests, DISABLED_make_blueprint) {}

TEST(PlayerTests, setEquipped) {
  Player p;
  Suit* s;

  p.setEquipped(s);

  EXPECT_EQ(s, p.getEquipped());
}
