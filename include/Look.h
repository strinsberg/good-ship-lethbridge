/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_LOOK_H
#define CALRISSIEN_2720_LOOK_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to inspect a game object.
  */
class Look : public Action
{
  public:
    Look(Player* p);
    virtual ~Look();

    std::string execute();

  private:
    Look(const Look& other);
    Look& operator=(const Look& other);
};

#endif // LOOK_H
