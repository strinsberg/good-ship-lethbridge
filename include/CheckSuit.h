#ifndef CHECKSUIT_H
#define CHECKSUIT_H

#include "Event.h"


class CheckSuit : public Event
{
  public:
    CheckSuit();
    virtual ~CheckSuit();

    std::string execute(Entity* affected);
    ObjectBlueprint* makeBlueprint() const;

  protected:

  private:
    CheckSuit(const CheckSuit& other);
    CheckSuit& operator=(const CheckSuit& other);
};

#endif // CHECKSUIT_H
