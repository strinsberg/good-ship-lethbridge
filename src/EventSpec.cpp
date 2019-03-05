/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */


#include "EventSpec.h"
#include <string>


EventSpec::EventSpec() : done(false), name("") {}

EventSpec::~EventSpec() {}

void EventSpec::setDone(bool d) {
  done = d;
}

bool EventSpec::isDone() const {
  return done;
}

void EventSpec::setName(const std::string& n) {
  name = n;
}

const std::string& EventSpec::getName() const {
  return name;
}

