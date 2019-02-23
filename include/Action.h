/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_ACTION_H
#define CALRISSIEN_2720_ACTION_H

#include "Command.h"
#inlcude "Player.h"


/**
  * Base class for actions the user wants the player to take.
  */
class Action : public Command {
 public:
  Action() : player(nullptr) {}
  virtual ~Action() {}

  /**
    * Set the entity that is responsible for the action. Does not
    * transfer ownership to the Action.
    * @param p the entity taking the action
    */
  virtual void SetEntity(Player* p);

 protected:
  Player* player;  // does not own the player

 private:
  Action(const Action&);
  Action& operator=(const Action&);
};

#endif // ACTION_H
