/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-19
 */


#include "Event.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>


Event::Event(std::string ID) : id(ID), done(false), once(false), observers(std::vector<Event*>()) {}

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

void Event::setOnce(bool o) {
  once = o;
}

void Event::subscribe(Event* e) {
  observers.push_back(e);
}

std::string Event::execute(Entity* e) {
  std::stringstream ss;
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    std::string result = (*it)->execute(e);
    if (!result.empty()) {
      ss << result;
      if (it + 1 != observers.end())
        ss << "\n";
    }
  }
  if (once)
    done = true;
  return ss.str();
}
