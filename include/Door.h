#ifndef CALRISSIEN_2720_DOOR_H
#define CALRISSIEN_2720_DOOR_H

#include "Entity.h"
#include "Room.h"


/**
  * A doorway to another room
  */
class Door : public Entity
{
  public:
    Door();
    virtual ~Door();
    void describe();
    void use(Entity&);
    void serialize(fstream&);

    /**
      * Set the room the door leads to
      * @param room the new destination
      */
    void setDestination(Room& room);

  protected:

  private:
    Room& destination;

    Door(const Door& other);
    Door& operator=(const Door& other);
};

#endif // DOOR_H
