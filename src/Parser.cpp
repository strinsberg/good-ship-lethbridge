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
#include "Talk.h"
#include "Help.h"
#include "Exit.h"
#include "Save.h"
#include "Load.h"
#include <string>
#include <sstream>


Parser::Parser(std::string in, Game* g) : input(in), game(g) {}

Parser::~Parser() {}

Command* Parser::parse() const {
  Command* c;
  std::string verb, next, noun;
  std::stringstream ss(input);

  ss >> verb;
  int i = 0;
  while (ss >> next) {
    if (i != 0)
      noun.append(" ");
    noun.append(next);
    i++;
  }

  if (verb == "get" || verb == "g") {
    c = new Get(game->getPlayer());
  } else if (verb == "drop" || verb == "d") {
    c = new Drop(game->getPlayer());
  } else if (verb == "look" || verb == "l") {
    c = new Look(game->getPlayer());
  } else if (verb == "inventory" || verb == "i") {
    c = new Inventory(game->getPlayer());
  } else if (verb == "use" || verb == "u") {
    c = new Use(game->getPlayer());
  } else if (verb == "talk" || verb == "t") {
    c = new Talk(game->getPlayer());
  } else if (verb == "exit" || verb == "e") {
    c = new Exit(game->getPlayer());
  } else if (verb == "help" || verb == "h") {
    c = new Help(game);
  } else if (verb == "quit" || verb == "q") {
    c = new Quit(game);
  } else if (verb == "save" || verb == "s") {
    c = new Save(game);
  } else if (verb == "load") {
    c = new Load(game);
  } else {
    c = new BadInput();
    c->setNoun(verb);
    return c;
  }

  c->setNoun(noun);
  return c;
}


const std::string& Parser::getInput() const {
  return input;
}
