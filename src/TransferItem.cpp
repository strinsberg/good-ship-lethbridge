/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "TransferItem.h"

TransferItem::TransferItem(std::string id, Entity* owner,
                 std::string iID, bool to)
      : OwnedEvent(id, owner), itemId(iID), toTarget(to) {}

TransferItem::~TransferItem() {}

std::string TransferItem::execute(Entity* target) {

}
