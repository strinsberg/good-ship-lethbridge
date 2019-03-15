/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#ifndef KEYLOCK_H
#define KEYLOCK_H

#include "Activate.h"
#include <string>


class KeyLock : public Activate {
 public:
  KeyLock(Entity* target, Entity* key, std::istream& is = std::cin,
          std::ostream& os = std::cout);
  virtual ~KeyLock();

  std::string execute(Entity* e);
  ObjectBlueprint* makeBlueprint();
  void setKey(Entity* key);
  Entity* getKey();
  void setSuccessEvent(Event*);
  Event* getSuccessEvent();

  void setFailMessage(std::string str);
  std::string getFailMessage();

 protected:
  Entity* key;
  Event* successEvent;
  std::string failMessage;

 private:
  KeyLock(const KeyLock& other);
  KeyLock& operator=(const KeyLock& other);
};

#endif // KEYLOCK_H
