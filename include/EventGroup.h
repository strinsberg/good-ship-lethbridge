/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "Event.h"
#include <vector>
#include <string>

/**
  * Event that can execute one or more events in order
  */
class EventGroup : public Event
{
  public:
    EventGroup();
    virtual ~EventGroup();
    std::string execute();
    ObjectBlueprint* makeBlueprint() const;

    /**
      * Add an event to the back of the group.
      * Transfers ownership to the EventGroup.
      * @param e an event
      */
    void addEvent(Event* e);

  protected:
    std::vector<Event*> events;  // Owns these events

  private:
    EventGroup(const EventGroup& other);
    EventGroup& operator=(const EventGroup& other);
};

#endif // EVENTGROUP_H
