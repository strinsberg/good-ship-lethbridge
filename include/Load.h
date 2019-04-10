/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef LOAD_H
#define LOAD_H

#include "GameCommand.h"
#include "Game.h"
#include <string>


/**
  * Command to load a saved game. This looks for a file with the players name
  * or a file starting with the name that is given to the command.
  */
class Load : public GameCommand {
 public:
  Load(Game* g);
  virtual ~Load();
  std::string execute();

 private:
  Load(const Load& other);
  Load& operator=(const Load& other);
};

#endif // LOAD_H
