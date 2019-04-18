/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "ToggleActive.h"

ToggleActive::ToggleActive(std::string id, Entity* owner)
    : OwnedEvent(id, owner) {}

ToggleActive::~ToggleActive() {}

std::string ToggleActive::execute(Entity* target) {
  bool active = owner->getState()->getActive();
  if (active)
    owner->getState()->setActive(false);
  else
    owner->getState()->setActive(true);
  return "";
}
