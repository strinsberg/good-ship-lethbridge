#ifndef LOAD_H
#define LOAD_H

#include "GameCommand.h"
#include <string>


/**
  * Command to load a saved game.
  */
class Load : public GameCommand
{
  public:
    Load();
    virtual ~Load();

    std::string execute();

  private:
    Load(const Load& other);
    Load& operator=(const Load& other);
};

#endif // LOAD_H
