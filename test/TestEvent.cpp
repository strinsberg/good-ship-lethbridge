/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Event.h"
#include "EventSpec.h"
#include "ObjectBlueprint.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>

// mock for testing Events concrete methods
class MockEvent : public Event {
 public:
  MockEvent() {};
  ~MockEvent() {};
  std::string execute() {}
  ObjectBlueprint* makeBlueprint() const {}
};

TEST(EventTests, constructor_get) {
  MockEvent m;
  Event* e = &m;
  EXPECT_EQ(e->getMessage(), "");
  EXPECT_EQ(e->getSpec(), nullptr);
}

TEST(EventTests, set_message) {
  MockEvent m;
  Event* e = &m;
  std::string message("You can't use that!");
  e->setMessage(message);
  EXPECT_EQ(e->getMessage(), "You can't use that!");
}

TEST(EventTests, set_spec) {
  MockEvent m;
  Event* e = &m;
  EventSpec* spec = new EventSpec();
  e->setSpec(spec);
  EXPECT_EQ(e->getSpec(), spec);
}
