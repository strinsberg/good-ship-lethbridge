/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "Event.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <vector>
#include <string>

/**
  * Event that executes one or more events all at once, but
  * in the order they were added.
  */
class EventGroup : public Event {
 public:
  EventGroup(std::istream& is = std::cin, std::ostream& os = std::cout);
  virtual ~EventGroup();
  virtual std::string execute(Entity* affected);
  virtual ObjectBlueprint* makeBlueprint() const;

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
