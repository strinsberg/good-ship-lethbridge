/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "StructuredEvents.h"
#include "ObjectBlueprint.h"
#include "ObjectWithContentsBlueprint.h"
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
      return events[events.size()-1]->execute(affected);
  }

  return events[currentEvent++]->execute(affected);
}

ObjectBlueprint* StructuredEvents::makeBlueprint() const {
  ObjectWithContentsBlueprint* b = new ObjectWithContentsBlueprint();

  b->setField("type", "structured_event");
  b->setField("message", message);
  b->setField("name", spec->getName());
  std::string d = spec->isDone() ? "true" : "false";
  b->setField("done", d);
  b->setField("index", std::to_string(currentEvent));

  for (auto e : events) {
    ObjectBlueprint* ebp = e->makeBlueprint();
    ebp->setField("owner", spec->getName());
    b->addBlueprint(ebp);
  }

  return b;
}
