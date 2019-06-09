/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "Question.h"

Question::Question(std::string q, std::string a)
    : Conditional("none"), question(q), answer(a) {}

Question::~Question() {}

bool Question::test(Entity* target) const {
  *out << question << std::endl;
  std::string input;
  *out << ">>> ";
  *in >> input;

  return input == answer;
}
