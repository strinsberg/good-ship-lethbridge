/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CHECKSUIT_H
#define CHECKSUIT_H

#include "Event.h"
#include "Room.h"
#include "ObjectBlueprint.h"
#include <string>


/**
  * Event to make sure the player is protected from the environment
  */
class CheckSuit : public Event {
 public:
  /**
    * Create a CheckSuit event for a given room.
    * @param here the room of the event.
    */
  CheckSuit(Room* here, std::istream& is = std::cin,
            std::ostream& os = std::cout);

  virtual ~CheckSuit();
  std::string execute(Entity* affected);
  ObjectBlueprint* makeBlueprint() const;

  /**
    * Returns the room of this event. Does not transfer ownership.
    * @return here
    */
  Room* getHere();

 protected:
  Room* here;  // Does not own this

 private:
  CheckSuit(const CheckSuit& other);
  CheckSuit& operator=(const CheckSuit& other);
};

#endif // CHECKSUIT_H
