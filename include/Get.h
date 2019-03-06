#ifndef CALRISSIEN_2720_GET_H
#define CALRISSIEN_2720_GET_H

#include "Action.h"
#include <string>


/**
  * Action to obtain a game object.
  */
class Get : public Action
{
  public:
    Get();
    virtual ~Get();

    std::string execute();

  private:
    Get(const Get& other);
    Get& operator=(const Get& other);
};

#endif // GET_H
