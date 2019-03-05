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
    : message(""), EntitySpec(nullptr), in(is), out(os) {}

Event::~Event() {}

Event::setMessage(std::string m) {

}

const std::string& Event::getMessage() const {
  return message;
}

Event::setSpec(EventSpec* s) {

}

const EventSpec* Event::getSpec() const {
  return spec;
}
