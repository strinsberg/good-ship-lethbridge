/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-03-08, 2019-04-20
 */

#include "Event.h"
#include "Inform.h"
#include "gtest/gtest.h"

TEST(EventTests, constructor) {
  Event e("id123");
  EXPECT_EQ("id123", e.getId());
  EXPECT_FALSE(e.isDone());
}

TEST(EventTests, set_get_done) {
  Event e("id123");
  e.setDone(true);
  EXPECT_TRUE(e.isDone());
}

TEST(EventTests, observers) {
  Event e("id123");
  Inform* inf = new Inform("inf456", "I like to fly!");
  Inform* inf2 = new Inform("inf987", "I like to take the train!");
  e.subscribe(inf);
  e.subscribe(inf2);
  EXPECT_EQ("I like to fly!\nI like to take the train!", e.execute(nullptr));
  delete inf;
  delete inf2;
}
