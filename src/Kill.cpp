#include "Kill.h"
#include "Entity.h"

Kill::Kill() {}

Kill::~Kill() {}

std::string Kill::execute(Entity* affected) {
  affected->getState()->setHidden(true);
  return affected->getSpec()->getName() + " is Dead!";
}

ObjectBlueprint* Kill::makeBlueprint() const {
  ObjectBlueprint* bp = new ObjectBlueprint();
  bp->setField("type", "kill");
  bp->setField("message", message);
  bp->setField("name", spec->getName());
  std::string d = spec->isDone() ? "true" : "false";
  bp->setField("done", d);
  return bp;
}
