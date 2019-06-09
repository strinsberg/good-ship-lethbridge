#include "EventConnector.h"
#include "Connector.h"
#include "Event.h"
#include "json.h"

using json = nlohmann::json;

EventConnector::EventConnector(json obj) : Connector(obj) {}

EventConnector::~EventConnector() {}

void EventConnector::collect(std::map<std::string, Event*>, std::map<std::string, Conditional*>) {

}

void EventConnector::visit(Event*) {

}
