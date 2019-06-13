#ifndef DGSL_DROP_H
#define DGSL_DROP_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to remove an item from the players inventory and place it in the
  * player's current room.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05
  */
class Drop : public Action {
  public:
    Drop(Player* p);
    virtual ~Drop();
    std::string execute();

  private:
    Drop(const Drop&);
    Drop& operator=(const Drop&);
};

#endif // DROP_H
