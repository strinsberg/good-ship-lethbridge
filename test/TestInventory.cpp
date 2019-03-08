/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Inventory.h"
#include <string>
#include "gtest/gtest.h"

TEST(InventoryTests, constructor_get) {
  Inventory i;
  EXPECT_EQ(i.getNoun(), "");
  EXPECT_EQ(i.getPlayer(), nullptr);
}

TEST(InventoryTests, set_noun) {
  Inventory i;
  i.setNoun("Laser");
  EXPECT_EQ(i.getNoun(), "Laser");
}
