#ifndef DGSL_BADINPUT_H
#define DGSL_BADINPUT_H

#include "Command.h"
#include <string>

/**
  * Deals with invalid input from the player.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-23
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
