/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */
#include "Npc.h"
#include "Container.h"
#include "gtest/gtest.h"
#include "Inform.h"
#include "Player.h"
TEST(TestNpc, describe) {
  Npc Max;

  Max.getSpec()->setDescription("this is max from your class");
  EXPECT_EQ("this is max from your class", Max.describe());
}

TEST(TestNpc, use) {
  Npc steve;
  Player* Max = new Player();

  Event* info = new Inform();
  info->setMessage("hi I am Steve");
  steve.setEvent(info);
  EXPECT_EQ("hi I am Steve", steve.use(Max));
  delete Max;
}
