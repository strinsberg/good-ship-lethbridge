/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#ifndef CALRISSIEN_2720_DOOR_H
#define CALRISSIEN_2720_DOOR_H

#include "Entity.h"
#include "Room.h"
#include <string>


/**
  * A doorway to another room
  */
class Door : public Entity {
 public:
  Door();
  virtual ~Door();
  virtual std::string describe() const;
  virtual std::string use(Entity&);
  virtual ObjectBlueprint* makeBlueprint() const = 0;

  /**
    * Set the room the door leads to. Does not transfer
    * ownership to the door.
    * @param room the new destination
    */
  void setDestination(Room* room);

 private:
  Room* destination;  // does not own this

  Door(const Door&);
  Door& operator=(const Door&);
};

#endif // DOOR_H
