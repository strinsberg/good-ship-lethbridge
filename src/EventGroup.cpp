/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include <string>
#include <sstream>

EventGroup::EventGroup() {}

EventGroup::~EventGroup() {
  for (auto e : events) {
    if (e != nullptr)
    delete e;
  }
}

void EventGroup::addEvent(Event* e) {
  events.push_back(e);
}

std::string EventGroup::execute() {
  std::stringstream ss;
  for (int i = 0; i < events.size(); i++) {
    std::string end = i < events.size() - 1 ? "\n" : "";
    ss << events[i]->execute() << end;
  }
  return ss.str();
}

ObjectBlueprint* EventGroup::makeBlueprint() const {
  // might need an object blueprint subclass
  // like this one that is a group of object Blueprints
}
