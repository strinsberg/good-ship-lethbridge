/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
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
