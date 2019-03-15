/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */


#ifndef HELP_H
#define HELP_H

#include "GameCommand.h"
#include "Game.h"
#include <string>


/**
  * Command to get help.
  */
class Help : public GameCommand {
 public:
  Help(Game* g);
  virtual ~Help();

  std::string execute();

 private:
  Help(const Help& other);
  Help& operator=(const Help& other);
};

#endif // HELP_H
