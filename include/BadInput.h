/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef BADINPUT_H
#define BADINPUT_H

#include "Command.h"
#include <string>

/**
  * An object to resolve invalid input from the player
  */
class BadInput : public Command {
 public:
  BadInput();
  virtual ~BadInput();
  std::string execute();

 private:
  BadInput(const BadInput&);
  BadInput& operator=(const BadInput&);
};

#endif // BADINPUT_H
