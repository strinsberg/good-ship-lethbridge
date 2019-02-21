#ifndef CALRISSIEN_2720_DOOR_H
#define CALRISSIEN_2720_DOOR_H

#include "Entity.h"
#include "Room.h"

class Door : public Entity
{
  public:
    Door();
    virtual ~Door();
    void describe();
    void use(Entity&);
    void serialize(fstream&);

    void setDestination(Room&);

  protected:

  private:
    Room& destination;

    Door(const Door& other);
    Door& operator=(const Door& other);
};

#endif // DOOR_H
