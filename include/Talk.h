#ifndef CALRISSIEN_2720_TALK_H
#define CALRISSIEN_2720_TALK_H

#include "Action.h"
#include <string>


/**
  * Action to talk to an NPC.
  */
class Talk : public Action
{
  public:
    Talk();
    virtual ~Talk();

    std::string execute();

  private:
    Talk(const Talk& other);
    Talk& operator=(const Talk& other);
};

#endif // TALK_H
