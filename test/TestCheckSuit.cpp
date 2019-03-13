/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-13
 */

#include "CheckSuit.h"
#include "Suit.h"
#include "Event.h"
#include "Item.h"
#include "Container.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(CheckSuitTests, constructor_get) {
  CheckSuit cs;
  EXPECT_EQ("", cs.getMessage());
  EXPECT_EQ(false, cs.getSpec()->isDone());
}
