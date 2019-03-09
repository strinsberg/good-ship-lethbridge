/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "ObjectWithContentsBlueprint.h"
#include "ObjectBlueprint.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

ObjectWithContentsBlueprint::ObjectWithContentsBlueprint()
    : contents(std::vector<ObjectBlueprint*>()) {}

ObjectWithContentsBlueprint::ObjectWithContentsBlueprint(const std::string& data)
    : ObjectBlueprint(data), contents(std::vector<ObjectBlueprint*>()) {}

ObjectWithContentsBlueprint::~ObjectWithContentsBlueprint() {
  for (auto o : contents)
    delete o;
}


void ObjectWithContentsBlueprint::addBlueprint(ObjectBlueprint* obj) {
  contents.push_back(obj);
}

const std::vector<ObjectBlueprint*>::iterator ObjectWithContentsBlueprint::begin() {
  return contents.begin();
}


const std::vector<ObjectBlueprint*>::iterator ObjectWithContentsBlueprint::end() {
  return contents.end();
}

std::string ObjectWithContentsBlueprint::toString() const {
  std::stringstream ss;
  ss << ObjectBlueprint::toString() << std::endl;
  for (size_t i = 0; i < contents.size(); i++) {
    ss << contents[i]->toString();
    if (i != contents.size() - 1)
      ss << std::endl;
  }
  return ss.str();
}
