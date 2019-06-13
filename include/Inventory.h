/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_INVENTORY_H
#define CALRISSIEN_2720_INVENTORY_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to view players inventory.
  */
class Inventory : public Action {
  public:
    Inventory(Player* p);
    virtual ~Inventory();
    std::string execute();

  private:
    Inventory(const Inventory& other);
    Inventory& operator=(const Inventory& other);
};

#endif // INVENTORY_H
