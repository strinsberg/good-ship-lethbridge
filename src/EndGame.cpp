/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "EndGame.h"
#include "Entity.h"
#include <sstream>
#include <string>

EndGame::EndGame() {}

EndGame::~EndGame() {}

std::string EndGame::execute(Entity* affected) {
  std::stringstream ss;
  affected->getState()->setHidden(true);
  ss << message << std::endl;
  return ss.str();
}

ObjectBlueprint* EndGame::makeBlueprint() const {
  ObjectBlueprint* bp = new ObjectBlueprint();
  bp->setField("type", "end_game");
  bp->setField("message", message);
  bp->setField("name", spec->getName());
  std::string d = spec->isDone() ? "true" : "false";
  bp->setField("done", d);
  return bp;
}
