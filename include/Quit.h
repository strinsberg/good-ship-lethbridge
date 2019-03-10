#ifndef QUIT_H
#define QUIT_H

#include "GameCommand.h"
#include <string>


/**
  * Command to quit the game.
  */
class Quit : public GameCommand
{
  public:
    Quit();
    virtual ~Quit();

    std::string execute();

  private:
    Quit(const Quit& other);
    Quit& operator=(const Quit& other);
};

#endif // QUIT_H
