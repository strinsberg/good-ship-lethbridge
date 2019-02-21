#ifndef CALRISSIEN_2720_EXIT_H
#define CALRISSIEN_2720_EXIT_H

#include "Action.h"


/**
  * The Action for when the user wants to try moving the player to
  * another room
  */
class Exit : public Action
{
  public:
    Exit() {}
    virtual ~Exit() {}

    void execute();

  private:
    Exit(const Exit&);
    Exit& operator=(const Exit&);
};

#endif // EXIT_H
