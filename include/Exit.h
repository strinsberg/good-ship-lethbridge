/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_EXIT_H
#define CALRISSIEN_2720_EXIT_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * The Action for when the user wants to try moving the player to
  * another room
  */
class Exit : public Action {
 public:
  Exit(Player* p);
  virtual ~Exit();
  std::string execute();

 private:
  Exit(const Exit&);
  Exit& operator=(const Exit&);
};

#endif // EXIT_H
