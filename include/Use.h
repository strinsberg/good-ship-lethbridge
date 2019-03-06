#ifndef CALRISSIEN_2720_USE_H
#define CALRISSIEN_2720_USE_H

#include "Action.h"
#include <string>


/**
  * Action to use a game object.
  */
class Use : public Action
{
  public:
    Use();
    virtual ~Use();

    std::string execute();

  protected:

  private:
    Use(const Use& other);
    Use& operator=(const Use& other);
};

#endif // USE_H
