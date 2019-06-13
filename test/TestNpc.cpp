/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Npc.h"
#include "gtest/gtest.h"

TEST(TestNpc, describe) {
    Npc Max("npc123");
    Max.getSpec()->setDescription("this is max from your class");
    EXPECT_EQ("this is max from your class", Max.describe());
}

TEST(TestNpc, default_talk) {
    Npc steve("npc123");
    EXPECT_EQ("They don't have anything to say!", steve.runEvent("talk", nullptr));
}
