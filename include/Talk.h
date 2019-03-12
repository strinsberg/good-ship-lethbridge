/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_TALK_H
#define CALRISSIEN_2720_TALK_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to talk to an NPC.
  */
class Talk : public Action
{
  public:
    Talk(Player* p);
    virtual ~Talk();

    std::string execute();

  private:
    Talk(const Talk& other);
    Talk& operator=(const Talk& other);
};

#endif // TALK_H
