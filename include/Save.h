#ifndef SAVE_H
#define SAVE_H

#include "GameCommand.h"
#include <string>


/**
  * Command to save the game.
  */
class Save : public GameCommand
{
  public:
    Save();
    virtual ~Save();

    std::string execute();

  private:
    Save(const Save& other);
    Save& operator=(const Save& other);
};

#endif // SAVE_H
