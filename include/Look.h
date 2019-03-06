#ifndef CALRISSIEN_2720_LOOK_H
#define CALRISSIEN_2720_LOOK_H

#include "Action.h"
#include <string>


/**
  * Action to inspect a game object.
  */
class Look : public Action
{
  public:
    Look();
    virtual ~Look();

    std::string execute();

  private:
    Look(const Look& other);
    Look& operator=(const Look& other);
};

#endif // LOOK_H
