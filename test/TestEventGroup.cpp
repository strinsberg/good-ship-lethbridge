/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include "Inform.h"
#include <string>
#include "gtest/gtest.h"

TEST(EventGroupTests, constructor_get) {
  EventGroup e;
  EXPECT_EQ(e.getMessage(), "");
  EXPECT_EQ(e.getSpec(), nullptr);
}

TEST(EventGroupTests, constructor_add_event_execute) {
  EventGroup e;

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  e.addEvent(i);

  EXPECT_EQ(e.execute(), "You can't use that!");
}

TEST(EventGroupTests, constructor_execute_group) {
  EventGroup e;

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  e.addEvent(i);

  Event* i2 = new Inform();
  i2->setMessage("You have died!");
  e.addEvent(i2);

  EXPECT_EQ(e.execute(), "You can't use that!\nYou have died!");
}

TEST(EventGroupTests, DISABLED_make_blueprint) {}

