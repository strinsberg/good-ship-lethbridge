#ifndef CALRISSIEN_2720_ACTION_H
#define CALRISSIEN_2720_ACTION_H

#include "Command.h"
#inlcude "Entity.h"


/**
  * Base class for actions the user wants the player to take.
  */
class Action : public Command
{
  public:
    Action();
    virtual ~Action();

    /**
      * Set the entity that is responsible for the action
      * @param entity the entity taking the action
      */
    virtual void SetEntity(Entity&);

  protected:
    Entity& entity;  // does not own the entity

  private:
    Action(const Action&);
    Action& operator=(const Action&);
};

#endif // ACTION_H
