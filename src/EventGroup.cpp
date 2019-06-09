/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "ObjectWithContentsBlueprint.h"
#include "Entity.h"
#include <string>
#include <sstream>
#include <vector>

EventGroup::EventGroup(std::string id)
  : Event(id), events(std::vector<Event*>()) {}

EventGroup::~EventGroup() {
  for (auto e : events) {
    if (e != nullptr)
      delete e;
  }
}

void EventGroup::addEvent(Event* e) {
  events.push_back(e);
}

std::string EventGroup::execute(Entity* affected) {
  std::stringstream ss;

  for (size_t i = 0; i < events.size(); i++) {
    std::string end = i < events.size() - 1 ? "\n" : "";
    std::string result = events[i]->execute(affected);
    if (!result.empty())
      ss << result << end;
  }

  return ss.str();
}
