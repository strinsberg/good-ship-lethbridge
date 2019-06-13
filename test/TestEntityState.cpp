/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-20
 */

#include "gtest/gtest.h"
#include "EntityState.h"
#include "Exceptions.h"

TEST(TestEntityState, EntityState_default) {
    EntityState e;
    EXPECT_EQ(true, e.getActive());
    EXPECT_EQ(true, e.getObtainable());
    EXPECT_EQ(false, e.getHidden());
}

TEST(TestEntityState, EntityState_constructor) {
    EntityState e(false, false, true);
    EXPECT_EQ(false, e.getActive());
    EXPECT_EQ(false, e.getObtainable());
    EXPECT_EQ(true, e.getHidden());
}

TEST(TestEntityState, set_get_obtainable) {
    EntityState e;
    e.setObtainable(false);

    EXPECT_EQ(false, e.getObtainable());
}

TEST(TestEntityState, set_get_active) {
    EntityState e;
    e.setActive(false);

    EXPECT_EQ(false, e.getActive());
}

TEST(TestEntityState, set_get_hidden) {
    EntityState e;
    e.setHidden(true);

    EXPECT_EQ(true, e.getHidden());
}
