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
  Action(Player* p);
  virtual ~Action();

  /**
   * @return the player
   */
  const Player* getPlayer() const;

  static Entity* findEntity(Player* p, std::string noun);

 protected:
  Player* player;  // does not own the player

    // Find an entity in the player or current room
  // Returns the entity or nullptr if the entity is not there
  // uses player and noun
  Entity* getEntity();

 private:

  Action(const Action&);
  Action& operator=(const Action&);
};

#endif // ACTION_H
