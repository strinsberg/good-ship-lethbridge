/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef SAVE_H
#define SAVE_H

#include "GameCommand.h"
#include "Game.h"
#include <string>


/**
  * Command to save the game.
  */
class Save : public GameCommand {
 public:
  Save(Game* g);
  virtual ~Save();

  std::string execute();

 private:
  Save(const Save& other);
  Save& operator=(const Save& other);
};

#endif // SAVE_H
