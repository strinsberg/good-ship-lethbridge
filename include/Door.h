/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_DOOR_H
#define CALRISSIEN_2720_DOOR_H

#include "Entity.h"
#include "Room.h"


/**
  * A doorway to another room
  */
class Door : public Entity {
 public:
  Door();
  virtual ~Door();
  void describe() const;
  void use(Entity&);
  void serialize(fstream&) const;

  /**
    * Set the room the door leads to
    * @param room the new destination
    */
  void setDestination(Room& room);

 private:
  Room& destination;

  Door(const Door& other);
  Door& operator=(const Door& other);
};

#endif // DOOR_H
