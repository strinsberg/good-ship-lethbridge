/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_ACTION_H
#define CALRISSIEN_2720_ACTION_H

#include "Command.h"
#include "Player.h"
#include <string>


/**
  * Base class for actions the user wants the player to take.
  */
class Action : public Command {
 public:
  Action(Player* p);
  virtual ~Action();

  /**
    * @return the player
    */
  const Player* getPlayer() const;

  /**
    * Allows finding an entity in a player and it's current room.
    * @param player the player
    * @param name then name of the entity
    */
  static Entity* findEntity(Player* player, std::string name);

 protected:
  Player* player;  // does not own the player

  // Calls findEntity with player and Command::noun
  Entity* getEntity();

 private:
  Action(const Action&);
  Action& operator=(const Action&);
};

#endif // ACTION_H
