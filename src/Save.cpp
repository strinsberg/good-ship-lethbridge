/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-03-14
 */

#include "Save.h"
#include "Game.h"
#include <string>
#include <fstream>

Save::Save(Game* g) :GameCommand(g) {}
Save::~Save() {}
std::string Save::execute() {
  std::ofstream fs;
  fs.open(game->getPlayer()->getSpec()->getName() + ".save", ios::trunc);  //might not be optimal with multi word player names
  for (auto r : game->getRooms()) {
    ObjectBlueprint* bp = r.second->makeBlueprint();
    fs << bp->toString() << std::endl;
    delete bp;
  }
  ObjectBlueprint* pbp = game->getPlayer()->makeBlueprint();
  fs << pbp->toString();
  delete pbp;
  fs.close();
  // should have error code to check if file operations are successful
  return "Game saved!!!";
}
