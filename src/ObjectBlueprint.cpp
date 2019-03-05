/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "ObjectBlueprint.h"
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using std::string;
using std::map;
using std::stringstream;

const string ObjectBlueprint::null = "null-field";

ObjectBlueprint::ObjectBlueprint() {}

ObjectBlueprint::ObjectBlueprint(const string& data)
  : record(map<string, string>()) {
  if (!data.empty())
    parse(data);
}

ObjectBlueprint::~ObjectBlueprint() {}

const string& ObjectBlueprint::getType() const {
  auto it = record.find("type");
  if (it == record.end())
    return null;
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
  ss << "type=" << getType() << ",\n";
  for (auto f : record) {
    if (f.first != "type")
      ss << f.first << '=' << f.second << ",\n";
  }
  ss << '}';
  return ss.str();
}

// Private Methods ///////////////////////////////////////////////////

void ObjectBlueprint::parse(const string& data) {
  size_t start = 0;
  size_t mid = 0;
  size_t end = 0;

  start = skipWhitespace(data, 1);  // ignore '{' and spaces or '\n'
  mid = data.find('=');
  end = data.find(',');

  while (end != string::npos) {
    record[ toLower( data.substr(start, mid - start) ) ]
      = data.substr(mid + 1, end - (mid + 1));

    start = skipWhitespace(data, end + 1);
    mid = data.find('=', start);
    end = data.find(',', start);
  }
}

size_t ObjectBlueprint::skipWhitespace(const string& str, size_t pos) {
  for (size_t i = pos; i < str.length(); i++) {
    char c = str[i];
    if (!isspace(c))
      return i;
  }
  return string::npos;
}

string ObjectBlueprint::toLower(const string& str) {
  string lower;
  for (auto c : str)
    lower.push_back( tolower(c) );
  return lower;
}
