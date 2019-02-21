#ifndef CALRISSIEN_2720_PLAYER_H
#define CALRISSIEN_2720_PLAYER_H

#include "Container.h"
#include "Room.h"


class Player : public Container
{
  public:
    Player();
    virtual ~Player();
    void describe();
    void use(Entity&);
    void serialize(fstream&);

    Room& getCurrentRoom();
    void setCurrentRoom(Room&);

  protected:

  private:
    Room& currentRoom;

    Player(const Player&);
    Player& operator=(const Player&);
};

#endif // PLAYER_H
