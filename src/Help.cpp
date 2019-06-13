/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Help.h"
#include "Game.h"
#include <string>

Help::Help(Game* g) :GameCommand(g) {}
Help::~Help() {}
std::string Help::execute() {
    std::string helptxt;
    helptxt = "available commands are use, get, drop, "
              "inventory, look, talk, save, load, quit, and exit.";
    return helptxt;
}
