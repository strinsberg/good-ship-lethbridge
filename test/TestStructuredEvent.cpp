/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "StructuredEvents.h"
#include "Inform.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>
#include "gtest/gtest.h"

TEST(StructuredEventsTests, constructor_get) {
  StructuredEvents s;
  EXPECT_EQ(s.getCurrentIndex(), 0);
  EXPECT_EQ(s.getRepeats(), true);
  EXPECT_EQ(s.getMessage(), "");
  EXPECT_EQ(s.getSpec(), nullptr);
}

TEST(StructuredEventsTests, set_repeats) {
  StructuredEvents s;
  s.setRepeats(false);
  EXPECT_EQ(s.getRepeats(), false);
}

TEST(StructuredEventsTests, execute_one_no_repeat) {
  StructuredEvents s;
  s.setRepeats(false);

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  s.addEvent(i);

  std::vector<Entity*> v;
  EXPECT_EQ(s.execute(v), "You can't use that!");
  EXPECT_EQ(s.getCurrentIndex(), 1);
  EXPECT_EQ(s.execute(v), "Nothing Happens");
  EXPECT_EQ(s.getCurrentIndex(), 1);
}

TEST(StructuredEventsTests, execute_many_repeat) {
  StructuredEvents s;
  s.setRepeats(false);

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  s.addEvent(i);

  Event* i2 = new Inform();
  i2->setMessage("You have died!");
  s.addEvent(i2);

  std::vector<Entity*> v;
  EXPECT_EQ(s.execute(v), "You can't use that!");
  EXPECT_EQ(s.getCurrentIndex(), 1);
  EXPECT_EQ(s.execute(v), "You have died!");
  EXPECT_EQ(s.getCurrentIndex(), 0);
  EXPECT_EQ(s.execute(v), "You can't use that!");
}

TEST(StructuredEventsTests, DISABLED_make_blueprint) {}
