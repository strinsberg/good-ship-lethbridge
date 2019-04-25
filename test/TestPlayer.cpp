/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-10, 2019-04-20
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
  Player p("id7193");
  EXPECT_EQ(nullptr, p.getCurrentRoom());
}

TEST(PlayerTests, set_room) {
  Player p("id7193");

  Room* r = new Room("id6t9");
  p.setCurrentRoom(r);

  EXPECT_EQ(r, p.getCurrentRoom());
  delete r;
}

TEST(PlayerTests, describe) {
  Player p("id7193");
  p.getSpec()->setDescription("That's You!");

  EXPECT_EQ("That's You!", p.describe());
}

TEST(PlayerTests, wear_suit_none_equipped) {
  Player p("id7193");
  Suit* s = new Suit();

  p.wearSuit(s);

  EXPECT_EQ(s, p.getSuit());
}

TEST(PlayerTests, wear_suit_already_wearing_one) {
  Player p("player123");
  Suit* s = new Suit();
  s->getSpec()->setId("suit123");
  p.wearSuit(s);

  Suit* s2 = new Suit();
  p.wearSuit(s2);

  EXPECT_EQ(s2, p.getSuit());
  EXPECT_EQ(s, p.searchById("suit123"));
}
