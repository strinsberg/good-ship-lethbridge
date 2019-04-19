/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-13
 */

#include "QuestionLock.h"
#include "Entity.h"
#include "Entity.h"
#include "gtest/gtest.h"

TEST(QuestionLockTests, constructor_get) {
  Entity* locked = new Entity();
  QuestionLock q(locked, "How much does my biography cost?", "$1e10");
  EXPECT_EQ(locked, q.getTarget());
  EXPECT_EQ("How much does my biography cost?", q.getQuestion());
  EXPECT_EQ("$1e10", q.getAnswer());
  EXPECT_EQ("", q.getMessage());
  delete locked;
}

TEST(QuestionLockTests, execute_right_answer) {
  Entity* locked = new Entity();
  locked->getState()->setActive(false);
  std::stringstream in("$1e10"), out;
  QuestionLock q(locked, "How much does my biography cost?", "$1e10", in, out);

  Entity* e = new Entity();
  EXPECT_EQ("Correct!", q.execute(e));
  EXPECT_EQ("How much does my biography cost? ", out.str());
  EXPECT_EQ(true, q.getSpec()->isDone());
  EXPECT_EQ(true, locked->getState()->getActive());

  delete locked;
  delete e;
}

TEST(QuestionLockTests, execute_wrong_answer) {
  Entity* locked = new Entity();
  locked->getState()->setActive(false);
  std::stringstream in("$25"), out;
  QuestionLock q(locked, "How much does my biography cost?", "$1e10", in, out);

  Entity* e = new Entity();
  EXPECT_EQ("Nope!", q.execute(e));
  EXPECT_EQ("How much does my biography cost? ", out.str());
  EXPECT_EQ(false, locked->getState()->getActive());

  delete locked;
  delete e;
}

TEST(QuestionLockTests, execute_already_done) {
  Entity* locked = new Entity();
  QuestionLock q(locked, "How much does my biography cost?", "$1e10");
  q.getSpec()->setDone(true);

  Entity* e = new Entity();
  EXPECT_EQ("Your so smart", q.execute(e));
  EXPECT_EQ(true, q.getSpec()->isDone());

  delete locked;
  delete e;
}

TEST(QuestionLockTests, make_blueprint) {
  Entity* locked = new Entity();
  locked->getState()->setActive(false);
  std::stringstream in("$1e10"), out;
  QuestionLock q(locked, "How much does my biography cost?", "$1e10", in, out);

  ObjectBlueprint* bp = q.makeBlueprint();
  EXPECT_EQ("{\ntype=questionlock,\nanswer=$1e10,\ndone=false,\nmessage=,"
            "\nname=,\nquestion=How much does my biography cost?,\ntarget=,\n}",
            bp->toString());

  delete locked;
  delete bp;
}
