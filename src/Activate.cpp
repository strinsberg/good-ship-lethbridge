/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Activate.h"
#include "Exceptions.h"
#include "Entity.h"
#include "ObjectBlueprint.h"
#include <string>

Activate::Activate(Entity* t, std::istream& is, std::ostream& os) : Event(is, os), target(t) {}

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
  ObjectBlueprint* bp = new ObjectBlueprint();
  bp->setField("type", "activate");
  bp->setField("target", target->getSpec()->getName());
  bp->setField("message", message);
  bp->setField("name", spec->getName());
  std::string done = spec->isDone() ? "true" : "false";
  bp->setField("done", done);

  return bp;
}

void Activate::setTarget(Entity* e) {
  target = e;
}

Entity* Activate::getTarget() {
  return target;
}
