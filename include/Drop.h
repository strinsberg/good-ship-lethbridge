/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_DROP_H
#define CALRISSIEN_2720_DROP_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to remove an item from the players inventory and
  * place it in the player's current room.
  */
class Drop : public Action {
 public:
  Drop(Player* p);
  virtual ~Drop();
  std::string execute();

 private:
  Drop(const Drop& other);
  Drop& operator=(const Drop& other);
};

#endif // DROP_H
