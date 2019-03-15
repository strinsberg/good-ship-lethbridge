#ifndef ENDGAME_H
#define ENDGAME_H

#include "Event.h"


class EndGame : public Event
{
  public:
    EndGame();
    virtual ~EndGame();

    std::string execute(Entity* affected);
    ObjectBlueprint* makeBlueprint() const;

  private:
    EndGame(const EndGame& other);
    EndGame& operator=(const EndGame& other);
};

#endif // ENDGAME_H
