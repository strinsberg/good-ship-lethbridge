/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "StructuredEvents.h"
#include "Entity.h"
#include <string>
#include <vector>

StructuredEvents::StructuredEvents(std::istream& is, std::ostream& os)
    : EventGroup(is, os), currentEvent(0), repeats(true) {}

StructuredEvents::~StructuredEvents() {}

int StructuredEvents::getCurrentIndex() {
  return currentEvent;
}

bool StructuredEvents::getRepeats() {
  return repeats;
}

void StructuredEvents::setRepeats(bool r) {
  repeats = r;
}

std::string StructuredEvents::execute(Entity* affected) {
  if (currentEvent == events.size()) {
    if (repeats)
      currentEvent = 0;
    else
      return "Nothing Happens";
  }

  return events[currentEvent++]->execute(affected);
}

ObjectBlueprint* StructuredEvents::makeBlueprint() const {

}
