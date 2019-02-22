/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_ACTION_H
#define CALRISSIEN_2720_ACTION_H

#include "Command.h"
#include "Player.h"
#include <iostream>


/**
  * Base class for actions the user wants the player to take.
  */
class Action : public Command {
 public:
  Action() : player(nullptr) {}
  virtual ~Action() {}

  /**
    * @param p the player
    */
  void setPlayer(Player* p) {
    player = p;
  }

 protected:
  Player* player;  // does not own the player

 private:
  Action(const Action&);
  Action& operator=(const Action&);
};

#endif // ACTION_H
