/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#ifndef DOOR_H
#define DOOR_H

#include "Entity.h"
#include "Room.h"
#include "ObjectBlueprint.h"
#include <string>

class Door : public Entity {
 public:
  Door();
  virtual ~Door();
  virtual std::string describe() const;
  virtual std::string use(Entity* user);
  virtual ObjectBlueprint* makeBlueprint() const;

  /**
    * Set a destination for the door to lead to.
    * @param room the destination room
    */
  void setDestination(Room* room);

  /**
    * Get the room the door leads to
    * @return destination
    */
  Room* getDestination();

  /**
    * Set a location of the door
    * @param room the location of the room
    */
  void setHere(Room* room);

  /**
    * Get the room the door is in
    * @return here
    */
  Room* getHere();

 private:
  Room* destination;  // Does not own this
  Room* here;

  Door(const Door& other);
  Door& operator=(const Door& other);
};

#endif // DOOR_H
