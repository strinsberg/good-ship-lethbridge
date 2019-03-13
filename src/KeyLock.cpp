/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "KeyLock.h"
#include "Container.h"
#include <typeinfo>

KeyLock::KeyLock(Entity* target, Entity* k) : Activate(target), key(k) {}

KeyLock::~KeyLock() {}

ObjectBlueprint* KeyLock::makeBlueprint() {}

std::string KeyLock::execute(Entity* affected) {
  if (Container* c = dynamic_cast<Container*>(affected)) {
      if (c->search(key->getSpec()->getName()))
        return Activate::execute(affected);
      else
        return "You don't have the key";
  }
  return "That can't hold a key";
}

void KeyLock::setKey(Entity* k) {
  key = k;
}

Entity* KeyLock::getKey() {
  return key;
}
