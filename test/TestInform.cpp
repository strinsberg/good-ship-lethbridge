/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "Inform.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>
#include "gtest/gtest.h"

TEST(InformTests, constructor_execute) {
  Inform i("id123", "You can't use that!");
  Entity* e = new Entity();
  EXPECT_EQ("You can't use that!", i.execute(e));
  delete e;
}
