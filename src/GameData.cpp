/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "GameData.h"
#include <string>

using std::string;

std::string GameData::eof() {return "end-of-data";}

GameData::GameData(const string& str) : data(str), begin(0), end(0) {}

GameData::~GameData() {}

string GameData::nextObject() {
  begin = data.find('{', end);

  if (begin == string::npos)
    return eof();

  end = data.find('}', begin);

  return data.substr(begin, end - begin + 1);
}

