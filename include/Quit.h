/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef QUIT_H
#define QUIT_H

#include "GameCommand.h"
#include "Game.h"
#include <string>


/**
  * Command to quit the game.
  */
class Quit : public GameCommand {
 public:
  Quit(Game* g);
  virtual ~Quit();
  std::string execute();

 private:
  Quit(const Quit& other);
  Quit& operator=(const Quit& other);
};

#endif // QUIT_H
