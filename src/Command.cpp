/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-23
 */

#include "Command.h"
#include <string>


Command::Command(std::string n) : noun(n) {}

Command::~Command() {}

void Command::setNoun(std::string n) {
    noun = n;
}

std::string Command::getNoun() const {
    return noun;
}
