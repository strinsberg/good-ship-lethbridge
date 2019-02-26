/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#ifndef CALRISSIEN_2720_ACTION_H
#define CALRISSIEN_2720_ACTION_H

#include "Command.h"
#include "Player.h"


/**
  * Base class for actions the user wants the player to take.
  */
class Action : public Command {
 public:
  Action();
  virtual ~Action();

  /**
    * Does not transfer ownership of player to the Action.
    * @param p the player taking the action
    */
  void setPlayer(Player* p);

   /**
    * @return the player
    */
  const Player* getPlayer() const;

 protected:
  Player* player;  // does not own the player

 private:
  Action(const Action&);
  Action& operator=(const Action&);
};

#endif // ACTION_H
