/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Activate.h"
#include "Exceptions.h"
#include "Entity.h"
#include <string>

Activate::Activate(Entity* t) : target(t) {}

Activate::~Activate() {}

std::string Activate::execute(Entity* e) {
  bool on = target->getState()->getActive();
  if (on)
    return "Already done";
  else {
    target->getState()->setActive(true);
    return message;
  }
}

ObjectBlueprint* Activate::makeBlueprint() const {

}

void Activate::setTarget(Entity* e) {
  target = e;
}

Entity* Activate::getTarget() {
  return target;
}
