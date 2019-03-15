#include "Kill.h"
#include "Entity.h"
#include <sstream>
#include <iostream>

Kill::Kill() {}

Kill::~Kill() {}

std::string Kill::execute(Entity* affected) {
  std::stringstream ss;
  affected->getState()->setHidden(true);
  ss << message << std::endl;
  ss << affected->getSpec()->getName() << " is Dead!";
  return ss.str();
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
