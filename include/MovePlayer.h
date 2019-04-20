#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H

#include "Event.h"
#include "Room.h"
#include <string>


class MovePlayer : public Event
{
  public:
    MovePlayer(std::string id, Room* destination);
    virtual ~MovePlayer();

    std::string execute(Entity* target);

  protected:
    Room* destination;

  private:
    MovePlayer(const MovePlayer& other);
    MovePlayer& operator=(const MovePlayer& other);
};

#endif // MOVEPLAYER_H
