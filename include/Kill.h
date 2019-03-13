#ifndef KILL_H
#define KILL_H

#include "Event.h"


class Kill : public Event
{
  public:
    Kill();
    virtual ~Kill();

    std::string execute(Entity* affected);
    ObjectBlueprint* makeBlueprint() const;

  protected:

  private:
    Kill(const Kill& other);
    Kill& operator=(const Kill& other);
};

#endif // KILL_H
