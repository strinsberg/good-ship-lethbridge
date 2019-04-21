/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef TRANSFERITEM_H
#define TRANSFERITEM_H

#include "Event.h"
#include "Container.h"
#include "Entity.h"
#include <string>


class TransferItem : public Event
{
  public:
    TransferItem(std::string id, Container* owner,
                 std::string itemId, bool toTarget=false);
    virtual ~TransferItem();

    std::string execute(Entity* target);

  private:
    Container* owner;  // does not own this
    std::string itemId;
    bool toTarget;

    TransferItem(const TransferItem& other);
    TransferItem& operator=(const TransferItem& other);
};

#endif // TRANSFERITEM_H
