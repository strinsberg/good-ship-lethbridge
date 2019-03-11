/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Quit.h"
#include "Exceptions.h"
#include "Game.h"
#include <string>

Quit::Quit(Game* g) : GameCommand(g) {}
Quit::~Quit() {}
std::string Quit::execute() {
  if (game == nullptr)
    throw unfinished_object_error("You have no game for quit object!");
  game->stop();
  return "Thanks for playing!";
}
