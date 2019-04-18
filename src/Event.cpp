/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-19
 */


#include "Event.h"
#include "ObjectBlueprint.h"
#include "EventSpec.h"
#include <string>
#include <iostream>


Event::Event(std::istream& is, std::ostream& os)
  : message(""), spec(nullptr), in(is), out(os) {
  spec = new EventSpec();
}

Event::~Event() {
  delete spec;
}

void Event::setMessage(const std::string& m) {
  message = m;
}

const std::string& Event::getMessage() const {
  return message;
}

void Event::setSpec(EventSpec* s) {
  delete spec;
  spec = s;
}

EventSpec* Event::getSpec() const {
  return spec;
}

std::string Event::getId() const {
  return id;
}

bool Event::isDone() const {
  return done;
}

void Event::setDone(bool d) {
  done = d;
}

void Event::subscribe(Event* e) {
  observers.push_back(e);
}
