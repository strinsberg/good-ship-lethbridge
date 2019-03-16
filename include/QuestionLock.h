/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef QUESTIONLOCK_H
#define QUESTIONLOCK_H

#include "Activate.h"
#include <string>

/**
  * A lock that requires the answer to a question to activate an entity.
  */
class QuestionLock : public Activate {
 public:
  /**
    * Create an event that will activate it's target when run.
    * @param target the target entity to activate.
    * @param question the question to ask
    * @param answer the answer to the question
    */
  QuestionLock(Entity* target, std::string question, std::string answer,
               std::istream& is = std::cin, std::ostream& os = std::cout);
  virtual ~QuestionLock();
  std::string execute(Entity* e);
  ObjectBlueprint* makeBlueprint();

  /**
    * Returns the question for the lock.
    * @return the question
    */
  std::string getQuestion();

  /**
    * Return the answer to the question.
    * @return the answer
    */
  std::string getAnswer();

 protected:
  std::string question, answer;

 private:
  QuestionLock(const QuestionLock& other);
  QuestionLock& operator=(const QuestionLock& other);
};

#endif // QUESTIONLOCK_H
