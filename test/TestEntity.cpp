/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-17
 */


#include "Entity.h"
#include "Inform.h"
#include <string>
#include <vector>
#include "gtest/gtest.h"

TEST(EntityTests, constructor) {
  Entity e;
  EXPECT_TRUE(e.getState()->getActive());
  EXPECT_EQ("", e.getSpec()->getName());
}

TEST(EntityTests, describe) {
  Entity e;
  e.getSpec()->setDescription("Healthy food");
  EXPECT_EQ("Healthy food", e.describe());
}

TEST(EntityTests, set_get_spec) {
  Entity e;
  EntitySpec* spec = new EntitySpec("spec123", "Apple", "Healthy food");
  e.setSpec(spec);
  EXPECT_EQ("Healthy food", e.getSpec()->getDescription());
}

TEST(EntityTests, set_get_state) {
  Entity e;
  e.setState(new EntityState(false, false, true));
  EXPECT_FALSE(e.getState()->getActive());
  EXPECT_FALSE(e.getState()->getObtainable());
  EXPECT_TRUE(e.getState()->getHidden());
}

TEST(EntityTests, add_run_event) {
  Entity e;
  Inform* inf = new Inform("inform123", "You should eat healthy food!");
  e.addEvent("use", inf);
  EXPECT_EQ("You should eat healthy food!", e.runEvent("use", &e));
}

TEST(EntityTests, matches) {
  Entity e;
  EntitySpec* spec = new EntitySpec("spec123", "Apple", "Healthy food");
  e.setSpec(spec);
  EXPECT_TRUE(e.matches("Apple"));
  EXPECT_TRUE(e.matches("Healthy"));
  EXPECT_FALSE(e.matches("Chocolate"));
}
