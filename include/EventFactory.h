/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-21
 */

#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "ObjectBlueprint.h"
#include "Room.h"
#include "Event.h"
#include "Conditional.h"
#include "EventGroup.h"
#include "json.h"
#include <vector>
#include <map>
#include <string>

using json = nlohmann::json;

class EventFactory
{
  public:
    EventFactory() {};
    virtual ~EventFactory();

    Event* makeEvent(const json& obj);
    EventGroup* makeGroup(const json& obj);

  private:

    EventFactory(const EventFactory& other);
    EventFactory& operator=(const EventFactory& other);
};

#endif // EVENTFACTORY_H
