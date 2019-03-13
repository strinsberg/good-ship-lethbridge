/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-13
 */

#include "Kill.h"
#include "Event.h"
#include "Item.h"
#include "Container.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(KillTests, constructor_get) {
  Kill k;
  EXPECT_EQ("", k.getMessage());
  EXPECT_EQ(false, k.getSpec()->isDone());
}

TEST(KillTests, kill_entity) {
  Kill k;
  Entity* toKill = new Item();
  toKill->getSpec()->setName("Ted");

  EXPECT_EQ("Ted is Dead!", k.execute(toKill));
  EXPECT_EQ(true, toKill->getState()->getHidden());
  delete toKill;
}
