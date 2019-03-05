/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */


#include "Event.h"
#include "ObjectBlueprint.h"
#include "EventSpec.h"
#include <string>
#include <iostream>


Event::Event(std::istream& is, std::ostream& os)
    : message(""), spec(nullptr), in(is), out(os) {}

Event::~Event() {
  if (spec != nullptr)
    delete spec;
}

void Event::setMessage(const std::string& m) {
  message = m;
}

const std::string& Event::getMessage() const {
  return message;
}

void Event::setSpec(EventSpec* s) {
  spec = s;
}

const EventSpec* Event::getSpec() const {
  return spec;
}
