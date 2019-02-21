#ifndef CALRISSIEN_2720_ROOM_H
#define CALRISSIEN_2720_ROOM_H

#include "Entity.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"

class Room : public Container
{
  public:
    Room();
    virtual ~Room();
    virtual void describe();
    virtual void use(Entity&);
    virtual void serialize(fstream&);

    virtual void enter(Entity&);
    virtual void exit(Entity&);

    void setEnter(Event*);
    void setExit(Event*);

  protected:
    Atmosphere atmosphere;
    Event* enterEvent;
    Event* exitEvent;

  private:
    Room(const Room&);
    Room operator=(const Room&);
};

#endif // ROOM_H
