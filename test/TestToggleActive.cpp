/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "ToggleActive.h"
#include "Player.h"
#include "gtest/gtest.h"

TEST(ToggleActiveEventTests, execute_active) {
  Player* p = new Player();
  ToggleActive* tog = new ToggleActive("toggle123", p);

  EXPECT_EQ("", tog->execute(p));
  EXPECT_FALSE(p->getState()->getActive());

  EXPECT_TRUE(tog->isDone());

  delete p;
}

TEST(ToggleActiveEventTests, execute_inactive) {
  Player* p = new Player();
  p->getState()->setActive(false);
  ToggleActive* tog = new ToggleActive("toggle123", p);

  tog->execute(p);
  EXPECT_TRUE(p->getState()->getActive());

  delete p;
}

TEST(ToggleActiveEventTests, execute_toggle) {
  Player* p = new Player();
  ToggleActive* tog = new ToggleActive("toggle123", p, false);

  tog->execute(p);
  EXPECT_FALSE(p->getState()->getActive());

  tog->execute(p);
  EXPECT_TRUE(p->getState()->getActive());

  EXPECT_FALSE(tog->isDone());

  delete p;
}
