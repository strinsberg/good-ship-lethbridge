/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "HasItem.h"

HasItem::HasItem(std::string id) : itemId(id) {}

HasItem::~HasItem() {}

bool HasItem::test(Entity* target) {
  Entity* item = target->search(itemId);  // wont work yet
  if (item != nullptr)
    return true;
  return false;
}
