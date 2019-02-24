/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Action.h"
#include "Player.h"
#include "gtest/gtest.h"


class MockAction : public Action {
 public:
   MockAction(): Action() {}
   ~MockAction() {}
   std::string execute() {return "executed";}
};

TEST(ActionTests, constructor) {
  MockAction m;
  Action* a = &m;
  EXPECT_EQ(a->getPlayer(), nullptr);
}

// will need proper player object when player is implemented
TEST(ActionTests, get_set_player) {
  MockAction m;
  Action* a = &m;
  Player* p = nullptr;
  a->setPlayer(p);
  EXPECT_EQ(a->getPlayer(), nullptr);
}

TEST(ActionTests, execute) {
  MockAction m;
  Command* c = &m;
  EXPECT_EQ(c->execute(), "executed");
}
