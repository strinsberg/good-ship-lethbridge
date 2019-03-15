#include "QuestionLock.h"
#include "Entity.h"
#include <string>

QuestionLock::QuestionLock(Entity* target, std::string q, std::string a,
                           std::istream& is, std::ostream& os)
  : Activate(target, is, os), question(q), answer(a) {}

QuestionLock::~QuestionLock() {}

std::string QuestionLock::execute(Entity* affected) {
  if (spec->isDone())
    return "Your so smart";

  out << question << " ";
  std::string ans;
  std::getline(in, ans);
  if (ans == answer) {
    target->getState()->setActive(true);
    spec->setDone(true);
    return "Correct!" + message;
  }

  return "Nope!";
}

ObjectBlueprint* QuestionLock::makeBlueprint() {
  ObjectBlueprint* bp = Activate::makeBlueprint();
  bp->setField("type", "questionlock");
  bp->setField("question", question);
  bp->setField("answer", answer);
  return bp;
}

std::string QuestionLock::getQuestion() {
  return question;
}
std::string QuestionLock::getAnswer() {
  return answer;
}
