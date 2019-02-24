/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#include "Command.h"
#include <string>

using std::string;

Command::Command() : noun("") {}
Command::~Command() {}

void Command::setNoun(const string& n) {
  noun = n;
}

const std::string& Command::getNoun() const {
  return noun;
}
