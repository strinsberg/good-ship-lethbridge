/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Parser.h"
#include "Command.h"
#include "BadInput.h"
#include "Quit.h"
#include "Get.h"
#include <string>
#include <sstream>


Parser::Parser(std::string in, Game* g) : input(in), game(g) {}

Parser::~Parser() {}

Command* Parser::parse() const {
  Command* c;
  std::string verb, noun;
  std::stringstream ss(input);

  ss >> verb;
  while (ss >> noun) {}

  if (verb == "quit") {
    c = new Quit(game);
  } else if (verb == "get") {
    c = new Get(game->getPlayer());
  } else {
    c = new BadInput();
    c->setNoun(verb);
  }

  return c;
}


const std::string& Parser::getInput() const {
  return input;
}
