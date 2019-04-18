/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "Question.h"
#include <sstream>
#include <string>
#include "gtest/gtest.h"

TEST(QuestionTests, test_and_constructor) {
  Question q("What is my name?", "steve");
  std::stringstream in("steve");
  std::stringstream out;
  q.setIn(in);
  q.setOut(out);
  EXPECT_EQ(true, q.test(nullptr));
  EXPECT_EQ("What is my name?\n>>> ", out.str());
}
