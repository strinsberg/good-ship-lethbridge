#ifndef DGSL_DOOR_H
#define DGSL_DOOR_H

#include "Entity.h"
#include "Room.h"
#include "Game.h"
#include <string>

/**
  * An one way connection between two rooms.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-23
  */
class Door : public Entity {
 public:
  /**
    * Creates a door that leads from one room to another. This is only
    * a one way conection from here to destination.
    * @param id a unique id.
    * @param here the room the door is in.
    * @param destination the room the door leads to.
    */
  Door(std::string id, Room* here, Room* destination);
  virtual ~Door();
  virtual std::string describe() const;

  /**
    * Get a pointer to the room the door leads to.
    * Does not transfer ownership.
    * @return the room the door leads to.
    */
  Room* getDestination();

  /**
    * Get a pointer to the room the door is in. Does not transfer ownership.
    * @return a pointer to the room the door is in.
    */
  Room* getHere();

 private:
  Room* destination;  // Does not own this
  Room* here;  // Does not own this

  Door(const Door& other);
  Door& operator=(const Door& other);
};

#endif // DOOR_H
