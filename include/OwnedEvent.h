/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef OWNEDEVENT_H
#define OWNEDEVENT_H

#include "Event.h"
#include "Entity.h"
#include <string>


class OwnedEvent : public Event {
  public:
    OwnedEvent(std::string id, Entity* owner);
    virtual ~OwnedEvent();

  protected:
    Entity* owner;  // Does not own this

  private:
    OwnedEvent(const OwnedEvent&);
    OwnedEvent& operator=(const OwnedEvent&);
};

#endif // OWNEDEVENT_H
