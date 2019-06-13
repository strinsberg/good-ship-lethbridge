/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-20
 */

#ifndef EQUIPSUIT_H
#define EQUIPSUIT_H

#include "OwnedEvent.h"
#include "Suit.h"
#include <string>

class EquipSuit : public Event {
  public:
    EquipSuit(std::string id, Suit* suit);
    virtual ~EquipSuit();
    std::string execute(Entity* target);

  protected:
    Suit* suit;

  private:
    EquipSuit(const EquipSuit& other);
    EquipSuit& operator=(const EquipSuit& other);
};

#endif // EQUIPSUIT_H
