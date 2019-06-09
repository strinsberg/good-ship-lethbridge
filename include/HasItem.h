/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef HASITEM_H
#define HASITEM_H

#include "Conditional.h"


class HasItem : public Conditional
{
  public:
    HasItem(std::string id, std::string item)
        : Conditional(id), itemId(item) {}
    HasItem(std::string itemId);
    virtual ~HasItem();

    /**
      * Test to see if the entity has an item.
      * @param target the entity to test
      * @return wether the entity has the item or not
      */
    bool test(Entity* target) const;

  private:
    std::string itemId;

    HasItem(const HasItem& other);
    HasItem& operator=(const HasItem& other);

};

#endif // HASITEM_H
