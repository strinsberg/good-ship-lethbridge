#ifndef CALRISSIEN_2720_ACTION_H
#define CALRISSIEN_2720_ACTION_H

#include "Command.h"
#inlcude "Entity.h"


class Action : public Command
{
  public:
    Action();
    virtual ~Action();
    virtual void execute() = 0;

    virtual void SetEntity(Entity&);

  protected:
    Entity& entity;

  private:
    Action(const Action&);
    Action& operator=(const Action&);
};

#endif // ACTION_H
