/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */


#include "ConditionalEvent.h"
#include "Player.h"
#include "HasItem.h"
#include "Entity.h"
#include "Inform.h"
#include "gtest/gtest.h"

TEST(ConditionalEventTests, success) {
  ConditionalEvent ce("id123");
  Player* p = new Player("id456");
  Entity* e = new Entity("id789");
  p->addEntity(e);

  HasItem* hi = new HasItem("id789");
  Inform* success = new Inform("id098", "You have an item");
  Inform* failure = new Inform("id876", "You have no item");
  ce.setCondition(hi);
  ce.setSuccess(success);
  ce.setFailure(failure);

  EXPECT_EQ("You have an item", ce.execute(p));
  delete p;
}

TEST(ConditionalEventTests, failure) {
  ConditionalEvent ce("id123");
  Player* p = new Player("id456");
  Entity* e = new Entity("id789");
  p->addEntity(e);

  HasItem* hi = new HasItem("id456");
  Inform* success = new Inform("id098", "You have an item");
  Inform* failure = new Inform("id876", "You have no item");
  ce.setCondition(hi);
  ce.setSuccess(success);
  ce.setFailure(failure);

  EXPECT_EQ("You have no item", ce.execute(p));
  delete p;
}
