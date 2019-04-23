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


Event::Event(std::string ID) : id(ID), done(false), observers(std::vector<Event*>()) {}

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

std::string Event::execute(Entity* e) {
  std::stringstream ss;
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    std::string result = (*it)->execute(e);
    std::cout << (*it)->getId() << std::endl;
    if (!result.empty()) {
      ss << result;
      if (it + 1 != observers.end())
        ss << "\n";
    }
  }
  return ss.str();
}
