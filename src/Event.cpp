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


Event::Event(std::string ID)
    : id(ID) {
}

Event::~Event() {}

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
