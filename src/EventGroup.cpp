/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <sstream>
#include <vector>

EventGroup::EventGroup() : events(std::vector<Event*>()) {}

EventGroup::~EventGroup() {
  for (auto e : events) {
    if (e != nullptr)
    delete e;
  }
}

void EventGroup::addEvent(Event* e) {
  events.push_back(e);
}

std::string EventGroup::execute(std::vector<Entity*>& affected) {
  std::stringstream ss;

  for (int i = 0; i < events.size(); i++) {
    std::string end = i < events.size() - 1 ? "\n" : "";
    ss << events[i]->execute(affected) << end;
  }

  return ss.str();
}

ObjectBlueprint* EventGroup::makeBlueprint() const {
  // might need an object blueprint subclass
  // like this one that is a group of object Blueprints
}
