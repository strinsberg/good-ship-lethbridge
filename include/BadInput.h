/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#ifndef BADINPUT_H
#define BADINPUT_H

#include "Command.h"
#include <string>


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
