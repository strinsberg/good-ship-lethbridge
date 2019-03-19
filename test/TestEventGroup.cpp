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
  EventGroup e;
  EXPECT_EQ(e.getMessage(), "");
  EXPECT_EQ(e.getSpec()->getName(), "");
}

TEST(EventGroupTests, constructor_add_event_execute) {
  EventGroup e;

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  e.addEvent(i);

  Entity* p;
  EXPECT_EQ(e.execute(p), "You can't use that!");
}

TEST(EventGroupTests, constructor_execute_group) {
  EventGroup e;

  Event* i = new Inform();
  i->setMessage("You can't use that!");
  e.addEvent(i);

  Event* i2 = new Inform();
  i2->setMessage("You have died!");
  e.addEvent(i2);

  Entity* p;
  EXPECT_EQ(e.execute(p), "You can't use that!\nYou have died!");
}

TEST(EventGroupTests, make_blueprint) {
  EventGroup eg;
  eg.setMessage("You should go home");
  eg.getSpec()->setName("go home");
  Inform* i = new Inform();
  i->setMessage("HAHAHAHAHA");
  eg.addEvent(i);
  ObjectBlueprint* bp = eg.makeBlueprint();
  EXPECT_EQ("{\ntype=event_group,\ndone=false,\nmessage=You should go home,"
            "\nname=go home,\n}\n{\ntype=inform,\ndone=false,"
            "\nmessage=HAHAHAHAHA,\nname=,\nowner=go home,\n}",
            bp->toString());
  delete bp;
}

