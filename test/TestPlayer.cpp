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

TEST(PlayerTests, setEquipped) {
  Player p;
  Suit* s = new Suit();

  p.setEquipped(s);

  EXPECT_EQ(s, p.getEquipped());
  delete s;
}
