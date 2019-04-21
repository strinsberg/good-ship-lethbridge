/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "TransferItem.h"
#include "Container.h"

TransferItem::TransferItem(std::string id, Container* own,
                 std::string iID, bool to)
      : Event(id), owner(own), itemId(iID), toTarget(to) {}

TransferItem::~TransferItem() {}

std::string TransferItem::execute(Entity* target) {
  if (done)
    return "";

  if (Container* con = dynamic_cast<Container*>(target)) {
    Entity* item;
    if (toTarget) {
      item = owner->searchAndRemove(itemId);
      if (item != nullptr) {
        con->addEntity(item);
        done = true;
        return "You have obtained " + item->getSpec()->getDescription();
      } else {
        return "Somebody made a mistake!";  // this really shouldn't happen
      }
    } else {
      item = con->searchAndRemove(itemId);
      if (item != nullptr) {
        owner->addEntity(item);
        done = true;
        return item->getSpec()->getDescription() + " was taken from you";
      } else {
        return "You don't have what you need!";
      }
    }
  }
  return "You can't transfer items to non-containers!";
}
