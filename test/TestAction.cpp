/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Action.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"


// mock class for Testing Actions concrete methods
class MockAction : public Action {
 public:
  MockAction() {}
  ~MockAction() {}
  std::string execute() {}
};

TEST(ActionTests, constructor) {
  MockAction m;
  Action* a = &m;
  EXPECT_EQ(a->getPlayer(), nullptr);
}

TEST(ActionTests, set_player) {
  MockAction m;
  Action* a = &m;
  Player* p;
  a->setPlayer(p);
  EXPECT_EQ(a->getPlayer(), p);
}
