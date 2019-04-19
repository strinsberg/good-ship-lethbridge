/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "ConditionalEvent.h"

ConditionalEvent::ConditionalEvent(std::string id)
    : Event(id), condition(nullptr), success(nullptr), failure(nullptr) {}

ConditionalEvent::~ConditionalEvent() {
    if (condition != nullptr)
      delete condition;
    if (success != nullptr)
      delete success;
    if (failure != nullptr)
      delete failure;
}

void ConditionalEvent::setCondition(Conditional* c) {
  if (condition != nullptr)
    delete condition;
  condition = c;
}

void ConditionalEvent::setSuccess(Event* s) {
  if (success != nullptr)
    delete success;
  success = s;
}

void ConditionalEvent::setFailure(Event* f) {
  if (failure != nullptr)
    delete failure;
  failure = f;
}

std::string ConditionalEvent::execute(Entity* e) {
  if (condition->test(e))
    return success->execute(e);
  else
    return failure->execute(e);
}
