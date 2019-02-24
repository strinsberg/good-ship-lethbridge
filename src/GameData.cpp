#include "GameData.h"
#include <string>

using std::string;

const std::string GameData::eof = "end-of-data";

GameData::GameData(const string& str) : data(str), begin(0), end(0) {}

GameData::~GameData() {}

string GameData::nextObject() {
  begin = data.find('{', end);

  if (begin == string::npos)
    return eof;

  end = data.find('}', begin);

  return data.substr(begin, end - begin + 1);
}

