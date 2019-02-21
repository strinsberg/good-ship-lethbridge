#ifndef CALRISSIEN_2720_GAME_H
#define CALRISSIEN_2720_GAME_H

#include "Room.h"
#include "Player.h"
#include <map>

class Game
{
  public:
    Game();
    virtual ~Game();
    void run();

    void setPlayer(Player*);

  protected:

  private:
    map<string, Room*> rooms;
    Player* player;

    Game(const Game&);
    Game& operator=(const Game&);
};

#endif // GAME_H
