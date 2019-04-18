/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "HasItem.h"
#include "Entity.h"
#include "Container.h"

HasItem::HasItem(std::string id) : itemId(id) {}

HasItem::~HasItem() {}

bool HasItem::test(Entity* target) const {
  if (Container* c = dynamic_cast<Container*>(target)) {
    Entity* item = c->search(itemId);  // checks name so will be false for now
    if (item != nullptr)
      return true;
    else
      return false;
  } else {
    return false;
  }
}
