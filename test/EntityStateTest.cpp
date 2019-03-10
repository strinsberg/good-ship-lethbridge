#include "gtest/gtest.h"
#include "EntityState.h"
#include "Exceptions.h"

TEST(TestEntityState, EntityState) {
  EntityState e;
  EXPECT_EQ(true, e.getActive());
  EXPECT_EQ(true, e.getObtainable());
  EXPECT_EQ(false, e.getHidden());
}

TEST(TestEntityState, setObtainable) {
  EntityState e;
  e.setObtainable(false);

  EXPECT_EQ(false, e.getObtainable());
}

TEST(TestEntityState, setActive) {
  EntityState e;
  e.setActive(false);

  EXPECT_EQ(false, e.getActive());
}

TEST(TestEntityState, setHidden) {
  EntityState e;
  e.setHidden(true);

  EXPECT_EQ(true, e.getHidden());
}
