/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef DOOR_H
#define DOOR_H

#include "Entity.h"
#include "Room.h"
#include "Game.h"
#include <string>

/**
  * An object that leads to another room.
  */
class Door : public Entity {
 public:
  Door(std::string id, Room* here, Room* destination);
  virtual ~Door();
  virtual std::string describe() const;

  /**
    * Get the room the door leads to
    * @return destination
    */
  Room* getDestination();

  /**
    * Get the room the door is in
    * @return here
    */
  Room* getHere();

 private:
  Room* destination;  // Does not own this
  Room* here;  // Does not own this

  Door(const Door& other);
  Door& operator=(const Door& other);
};

#endif // DOOR_H
