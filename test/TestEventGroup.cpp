/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include <string>
#include "gtest/gtest.h"

TEST(EventGroupTests, constructor_get) {
  EventGroup e;
  EXPECT_EQ(e.getMessage(), "");
  EXPECT_EQ(e.getSpec(), nullptr);
}

// Create a bunch of inform events to add for some tests
