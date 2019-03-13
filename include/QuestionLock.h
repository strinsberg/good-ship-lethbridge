#ifndef QUESTIONLOCK_H
#define QUESTIONLOCK_H

#include "Activate.h"


class QuestionLock : public Activate
{
  public:
    QuestionLock(Entity* target, std::string question, std::string answer, std::istream& is = std::cin, std::ostream& os = std::cout);
    virtual ~QuestionLock();
    std::string execute(Entity* e);
    ObjectBlueprint* makeBlueprint();

    std::string getQuestion();
    std::string getAnswer();

  protected:
    std::string question, answer;

  private:
    QuestionLock(const QuestionLock& other);
    QuestionLock& operator=(const QuestionLock& other);
};

#endif // QUESTIONLOCK_H
