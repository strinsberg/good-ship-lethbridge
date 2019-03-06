#ifndef CALRISSIEN_2720_INVENTORY_H
#define CALRISSIEN_2720_INVENTORY_H

#include "Action.h"
#include <string>


/**
  * Action to view players inventory.
  */
class Inventory : public Action
{
  public:
    Inventory();
    virtual ~Inventory();

    std::string execute();

  private:
    Inventory(const Inventory& other);
    Inventory& operator=(const Inventory& other);
};

#endif // INVENTORY_H
