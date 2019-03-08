/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "EventGroup.h"
#include "Event.h"
#include <string>

EventGroup::EventGroup() {}

EventGroup::~EventGroup() {
  for (auto e : events) {
    if (e != nullptr)
    delete e;
  }
}

void EventGroup::addEvent(Event* e) {

}

std::string EventGroup::execute() {
  return message;
}

ObjectBlueprint* EventGroup::makeBlueprint() const {

}
