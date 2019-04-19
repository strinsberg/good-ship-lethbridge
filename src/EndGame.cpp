/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "EndGame.h"
#include "Entity.h"
#include <sstream>
#include <string>

EndGame::EndGame(std::string id) : Event(id) {}

EndGame::~EndGame() {}

std::string EndGame::execute(Entity* affected) {
  std::stringstream ss;
  affected->getState()->setHidden(true);
  //ss << message << std::endl;
  return ss.str();
}
