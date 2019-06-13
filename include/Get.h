/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_GET_H
#define CALRISSIEN_2720_GET_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to obtain a game object.
  */
class Get : public Action {
  public:
    Get(Player* p);
    virtual ~Get();
    std::string execute();

  private:
    Get(const Get& other);
    Get& operator=(const Get& other);
};

#endif // GET_H
