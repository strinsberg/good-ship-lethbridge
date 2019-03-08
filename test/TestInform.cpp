/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "Inform.h"
#include "Event.h"
#include "EventSpec.h"
#include "ObjectBlueprint.h"
#include <string>
#include <sstream>
#include "gtest/gtest.h"

TEST(InformTests, constructor_get) {
  Inform i;
  EXPECT_EQ(i.getMessage(), "");
  EXPECT_EQ(i.getSpec(), nullptr);
}

TEST(InformTests, set_message) {
  std::string message("You can't use that!");
  Inform i;
  i.setMessage(message);
  EXPECT_EQ(i.getMessage(), "You can't use that!");
}

TEST(InformTests, set_spec) {
  Inform i;
  EventSpec* spec = new EventSpec();
  i.setSpec(spec);
  EXPECT_EQ(i.getSpec(), spec);
}
