/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
#include "ObjectBlueprint.h"
#include "KeyLock.h"
#include <string>


/**
  * Any game entity that is only a spec, state, and use event. With no
  * other special additions.
  */
class Item : public Entity {
 public:
  Item();
  virtual ~Item();
  virtual std::string describe() const;
  virtual std::string use(Entity* user);
  virtual ObjectBlueprint* makeBlueprint() const;

 private:
  Item(const Item& other);
  Item& operator=(const Item& other);
};

#endif // ITEM_H
