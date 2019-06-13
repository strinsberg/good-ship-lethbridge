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


TEST(StructuredEventsTests, execute_one_no_repeat) {
    StructuredEvents s("id123");

    Event* i = new Inform("id456", "You can't use that!");
    s.addEvent(i);

    Entity* p;
    EXPECT_EQ(s.execute(p), "You can't use that!");
    EXPECT_EQ(s.execute(p), "You can't use that!");
}

TEST(StructuredEventsTests, execute_many_repeat) {
    StructuredEvents s("id123", true);

    Event* i = new Inform("id456", "You can't use that!");
    s.addEvent(i);

    Event* i2 = new Inform("id789", "You have died!");
    s.addEvent(i2);

    Entity* p;
    EXPECT_EQ(s.execute(p), "You can't use that!");
    EXPECT_EQ(s.execute(p), "You have died!");
    EXPECT_EQ(s.execute(p), "You can't use that!");
}
