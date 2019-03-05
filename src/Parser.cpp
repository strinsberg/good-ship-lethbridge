/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Parser.h"
#include "Command.h"
#include "BadInput.h"
#include <string>
#include <sstream>


Parser::Parser(std::string in) {
  input = in;
}

Parser::~Parser() {}

Command* Parser::parse() const {
  Command* c;
  std::string verb, noun;
  std::stringstream ss(input);

  ss >> verb;
  while (ss >> noun) {}

  if (0) {  //add cases here for other commands as they are ready
    // use Action or Game command pointer first to be able to save player
    // or game
    // then save it to c to be returned.
    // or make their constructors take player and game as arg.
    c = nullptr;
  } else {
    c = new BadInput();
    c->setNoun(verb);
  }

  return c;
}


const std::string& Parser::getInput() const {
  return input;
}
