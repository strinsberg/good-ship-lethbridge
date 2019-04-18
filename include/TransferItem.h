/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef TRANSFERITEM_H
#define TRANSFERITEM_H

#include "OwnedEvent.h"
#include <string>


class TransferItem : public OwnedEvent
{
  public:
    TransferItem(std::string id, Entity* owner,
                 std::string itemId, bool toTarget=false);
    virtual ~TransferItem();

    std::string execute(Entity* target);

  private:
    std::string itemId;
    bool toTarget;

    TransferItem(const TransferItem& other);
    TransferItem& operator=(const TransferItem& other);
};

#endif // TRANSFERITEM_H
