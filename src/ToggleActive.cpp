/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "ToggleActive.h"

ToggleActive::ToggleActive(std::string id, Entity* owner, bool oneTime)
    : OwnedEvent(id, owner), once(oneTime) {}

ToggleActive::~ToggleActive() {}

std::string ToggleActive::execute(Entity* target) {
  if (!done) {
    bool active = owner->getState()->getActive();
    if (active)
      owner->getState()->setActive(false);
    else
      owner->getState()->setActive(true);
    if (once)
      done = true;
  }
  return "";
}
