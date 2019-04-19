/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include "Inform.h"
#include "Entity.h"
#include <string>
#include <vector>
#include "gtest/gtest.h"

TEST(EventGroupTests, constructor_get) {
}

TEST(EventGroupTests, constructor_add_event_execute) {
  EventGroup e("id123");

  Event* i = new Inform("i123", "You can't use that!");
  e.addEvent(i);

  Entity* p;
  EXPECT_EQ(e.execute(p), "You can't use that!");
}

TEST(EventGroupTests, constructor_execute_group) {
  EventGroup e("id123");

  Event* i = new Inform("i123", "You can't use that!");
  e.addEvent(i);

  Event* i2 = new Inform("i456", "You have died!");
  e.addEvent(i2);

  Entity* p;
  EXPECT_EQ(e.execute(p), "You can't use that!\nYou have died!");
}
