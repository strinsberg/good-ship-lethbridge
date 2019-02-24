/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Command.h"
#include "gtest/gtest.h"
#include <string>


// mock for testing command
class MockCommand : public Command {
 public:
  MockCommand() {};
  ~MockCommand() {};
  std::string execute() {return "executed";}
};

TEST(CommandTests,constructor) {
  MockCommand m;
  Command* c = &m;
  EXPECT_EQ(c->getNoun(), "");
}

TEST(CommandTests, set_get_noun) {
  MockCommand m;
  Command* c = &m;
  c->setNoun("Laser");
  EXPECT_EQ(c->getNoun(), "Laser");
}

TEST(CommandTests, execute) {
  MockCommand m;
  Command* c = &m;
  EXPECT_EQ(c->execute(), "executed");
}
