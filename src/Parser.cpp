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
#include "Drop.h"
#include "Look.h"
#include "Inventory.h"
#include "Use.h"
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
  } else if (verb == "get" || verb == "g") {
    c = new Get(game->getPlayer());
  } else if (verb == "drop" || verb == "d") {
    c = new Drop(game->getPlayer());
  } else if (verb == "look" || verb == "l") {
    c = new Look(game->getPlayer());
  } else if (verb == "inventory" || verb == "i") {
    c = new Inventory(game->getPlayer());
  } else if (verb == "use" || verb == "u") {
    c = new Use(game->getPlayer());
  } else {
    c = new BadInput();
    c->setNoun(verb);
    return c;
  }

  c->setNoun(noun1.str());
  return c;
}


const std::string& Parser::getInput() const {
  return input;
}
