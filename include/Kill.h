#ifndef KILL_H
#define KILL_H

#include "Event.h"
#include <string>

/**
  * An event to kill an entity. Sets the entities hidden value to true.
  */
class Kill : public Event {
 public:
  Kill();
  virtual ~Kill();
  std::string execute(Entity* affected);
  ObjectBlueprint* makeBlueprint() const;

 private:
  Kill(const Kill& other);
  Kill& operator=(const Kill& other);
};

#endif // KILL_H
