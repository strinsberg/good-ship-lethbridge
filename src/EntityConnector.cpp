#include "EntityConnector.h"
#include "json.h"

using json = nlohmann::json;

EntityConnector::EntityConnector(json obj) : Connector(obj) {}

EntityConnector::~EntityConnector() {}

void EntityConnector::collect(std::map<std::string, Entity*>, std::map<std::string, Event*>) {}
void EntityConnector::visit(Entity*) {}
void EntityConnector::visit(Container*) {}
