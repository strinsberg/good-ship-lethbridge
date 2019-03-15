/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "KeyLock.h"
#include "Container.h"
#include <sstream>
#include <typeinfo>

KeyLock::KeyLock(Entity* target, Entity* k, std::istream& is, std::ostream& os)
  : Activate(target, is, os), key(k), successEvent(nullptr),
    failMessage("You don't have what you need") {}

KeyLock::~KeyLock() {
  if (successEvent != nullptr)
    delete successEvent;
}

ObjectBlueprint* KeyLock::makeBlueprint() {
  ObjectBlueprint* bp = Activate::makeBlueprint();
  bp->setField("type", "keylock");
  bp->setField("key", key->getSpec()->getName());
  return bp;
}

std::string KeyLock::execute(Entity* affected) {
  if (Container* c = dynamic_cast<Container*>(affected)) {
    if (c->search(key->getSpec()->getName())) {
      std::stringstream ss;
      if (successEvent != nullptr)
        ss << successEvent->execute(affected) << std::endl;
      ss << Activate::execute(affected);
      return ss.str();
    } else {
      return failMessage;
    }
  }
  return "That can't hold a key";
}

void KeyLock::setKey(Entity* k) {
  key = k;
}

Entity* KeyLock::getKey() {
  return key;
}

void KeyLock::setSuccessEvent(Event* e) {
  successEvent = e;
}

Event* KeyLock::getSuccessEvent() {
  return successEvent;
}

void KeyLock::setFailMessage(std::string str) {
  failMessage = str;
}
std::string KeyLock::getFailMessage() {
  return failMessage;
}

