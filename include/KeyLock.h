/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#ifndef KEYLOCK_H
#define KEYLOCK_H

#include "Activate.h"
#include <string>


/**
  * An event that will activate a target entity when the user has the key
  * object in their inventory. Also can be used to run an event when the key
  * key is given.
  */
class KeyLock : public Activate {
 public:
  /**
    * Creates a lock that will activate target when the user has the key.
    * @param target the object to activate
    * @param key the item needed to activate the target
    * @param in an istream (default cin)
    * @param out an ostream (default cout)
    */
  KeyLock(Entity* target, Entity* key, std::istream& is = std::cin,
          std::ostream& os = std::cout);

  virtual ~KeyLock();
  std::string execute(Entity* e);
  ObjectBlueprint* makeBlueprint();

  /**
    * Set the key object. Does not transfer ownership.
    * @param key the new key.
    */
  void setKey(Entity* key);

  /**
    * Returns the key for the lock. Does not transfer ownership.
    * @return the key entity.
    */
  Entity* getKey();

  /**
    * Set the event to run on success. Does not transfer ownership.
    * @param event the new success event
    */
  void setSuccessEvent(Event* event);

  /**
    * Returns the success event. Does not transfer ownership.
    * @return the success event.
    */
  Event* getSuccessEvent();

  /**
    * A special message to print when the event runs without the key.
    * @param the new fail message
    */
  void setFailMessage(std::string str);

  /**
    * Returns the fail message
    * @param the fail message
    */
  std::string getFailMessage();

 protected:
  Entity* key;  // does not own this
  Event* successEvent;  // does not own this
  std::string failMessage;

 private:
  KeyLock(const KeyLock& other);
  KeyLock& operator=(const KeyLock& other);
};

#endif // KEYLOCK_H
