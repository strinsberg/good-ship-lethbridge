/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

 #include "ObjectBlueprint.h"
#include <string>
#include <map>
#include <sstream>

using std::string;
using std::map;
using std::stringstream;

const string ObjectBlueprint::null = "null-field";

ObjectBlueprint::ObjectBlueprint(const string& data)
    : record(map<string, string>()) {
  if (!data.empty())
    parse(data);
}

ObjectBlueprint::~ObjectBlueprint() {}

const string& ObjectBlueprint::getType() const {
  auto it = record.find("type");
  return it->second;
}

const string& ObjectBlueprint::getField(const string& key) const {
  auto it = record.find(key);
  if (it == record.end())
    return null;
  return it->second;
}

bool ObjectBlueprint::setField(const string& key, const string& value) {
  record[key] = value;
}

string ObjectBlueprint::toString() const {
  stringstream ss;
  ss << '{' << '\n';
  ss << "type=" << getType() << ",\n";  // throws if object has no type
  for (auto f : record) {
    if (f.first != "type")
      ss << f.first << '=' << f.second << ",\n";
  }
  ss << '}';
  return ss.str();
}

void ObjectBlueprint::parse(const string& data) {

}
