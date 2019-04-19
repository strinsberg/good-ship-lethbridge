/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-18
 */

#include "EndGame.h"
#include "Event.h"
#include "Entity.h"
#include <string>
#include "gtest/gtest.h"

TEST(EndGameTest, execute) {
  Entity* i = new Entity();
  EndGame eg("eg123");
  eg.setMessage("You win!!!");
  EXPECT_EQ("You win!!!\n", eg.execute(i));
  delete i;
}

TEST(EndGameTest, make_blueprint) {
  EndGame eg("eg123");
  eg.setMessage("You win!!!");
  ObjectBlueprint* bp = eg.makeBlueprint();
  EXPECT_EQ("{\ntype=end_game,\ndone=false,\nmessage=You win!!!,\nname=,\n}",
            bp->toString());
  delete bp;
}
