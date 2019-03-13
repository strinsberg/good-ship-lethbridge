#include "Kill.h"
#include "Entity.h"

Kill::Kill() {}

Kill::~Kill() {}

std::string Kill::execute(Entity* affected) {
  affected->getState()->setHidden(true);
  return affected->getSpec()->getName() + " is Dead!";
}

ObjectBlueprint* Kill::makeBlueprint() const {

}
