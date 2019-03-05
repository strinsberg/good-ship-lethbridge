/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Command.h"
#include <string>
#include "gtest/gtest.h"


// mock for testing Commands concrete methods
class MockCommand : public Command {
 public:
  MockCommand() {}
  ~MockCommand() {}
  std::string execute() {}
};

TEST(CommandTests, constructor_get) {
  MockCommand m;
  Command* c = &m;
  EXPECT_EQ(c->getNoun(), "");
}

TEST(CommandTests, set_noun) {
  MockCommand m;
  Command* c = &m;
  c->setNoun("Laser");
  EXPECT_EQ(c->getNoun(), "Laser");
}
