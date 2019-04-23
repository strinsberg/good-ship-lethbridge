/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "ToggleActive.h"

ToggleActive::ToggleActive(std::string id, Entity* targ, bool oneTime)
    : Event(id), target(targ), once(oneTime) {}

ToggleActive::~ToggleActive() {}

std::string ToggleActive::execute(Entity* affected) {
  if (!done) {
    bool active = target->getState()->getActive();
    if (active)
      target->getState()->setActive(false);
    else
      target->getState()->setActive(true);
    if (once)
      done = true;
    return Event::execute(affected);
  }
  return "";
}
