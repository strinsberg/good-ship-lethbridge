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
  EXPECT_EQ("", s.getSpec()->getName());
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

  Entity* p;
  EXPECT_EQ(s.execute(p), "You can't use that!");
  EXPECT_EQ(s.getCurrentIndex(), 1);
  EXPECT_EQ(s.execute(p), "You can't use that!");
  EXPECT_EQ(s.getCurrentIndex(), 1);
}

TEST(StructuredEventsTests, execute_many_repeat) {
  StructuredEvents s;

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  s.addEvent(i);

  Event* i2 = new Inform();
  i2->setMessage("You have died!");
  s.addEvent(i2);

  Entity* p;
  EXPECT_EQ(s.execute(p), "You can't use that!");
  EXPECT_EQ(s.getCurrentIndex(), 1);
  EXPECT_EQ(s.execute(p), "You have died!");
  EXPECT_EQ(s.getCurrentIndex(), 2);
  EXPECT_EQ(s.execute(p), "You can't use that!");
  EXPECT_EQ(s.getCurrentIndex(), 1);
}

TEST(StructuredEventsTests, make_blueprint) {
  StructuredEvents s;

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  s.addEvent(i);

  Event* i2 = new Inform();
  i2->setMessage("You have died!");
  s.addEvent(i2);

  ObjectBlueprint* bp = s.makeBlueprint();
  EXPECT_EQ("{\ntype=structured_event,\ndone=false,\nindex=0,\nmessage=,"
            "\nname=,\n}\n{\ntype=inform,\ndone=false,"
            "\nmessage=You can't use that!,\nname=,\nowner=,\n}\n"
            "{\ntype=inform,\ndone=false,\nmessage=You have died!,\nname=,"
            "\nowner=,\n}", bp->toString());
  delete bp;
}
