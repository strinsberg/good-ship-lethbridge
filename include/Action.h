#ifndef DGSL_ACTION_H
#define DGSL_ACTION_H

#include "Command.h"
#include "Player.h"
#include <string>


/**
  * Base class for actions the user wants the player to take.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-23
  */
class Action : public Command {
  public:
    Action(Player* p);
    virtual ~Action();

    /**
      * Returns a pointer to the player. Does not transfer ownership.
      * @return the player taking the action.
      */
    const Player* getPlayer() const;

  protected:
    /**
      * The player taking the action. Action Does not own this.
      */
    Player* player;

    /**
      * Returns a pointer to the entity that matches the noun and is accessible
      * to the player. Does not transfer ownership.
      * @return a pointer to the entity matching the noun or nullptr if
      * there isn't one.
      */
    Entity* getEntity();

  private:
    Action(const Action&);
    Action& operator=(const Action&);
};

#endif // ACTION_H
