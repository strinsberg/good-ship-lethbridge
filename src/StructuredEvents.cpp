#include "StructuredEvents.h"

StructuredEvents::StructuredEvents() : currentEvent(0), repeats(true) {}

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

std::string StructuredEvents::execute() {
  return message;
}

ObjectBlueprint* StructuredEvents::makeBlueprint() const {

}
