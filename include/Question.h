/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef QUESTION_H
#define QUESTION_H

#include "Conditional.h"
#include "Interactable.h"


class Question : public Conditional, public Interactable {
  public:
    /**
      * Create a question conditional with a question and answer.
      * @param question the question
      * @param answer the answer
      */
    Question(std::string question, std::string answer);
    Question(std::string id, std::string q, std::string a)
        : Conditional(id), question(q), answer(a) {}
    virtual ~Question();

    /**
      * Ask the player a question and return true if they get it right.
      * @param target the player
      */
    bool test(Entity* target) const;

  private:
    std::string question;
    std::string answer;

    Question(const Question&);
    Question& operator=(const Question&);
};

#endif // QUESTION_H
