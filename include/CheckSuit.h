#ifndef CHECKSUIT_H
#define CHECKSUIT_H

#include "Event.h"
#include "Room.h"
#include "ObjectBlueprint.h"
#include <string>


class CheckSuit : public Event
{
  public:
    CheckSuit(Room* here, std::istream& is = std::cin, std::ostream& os = std::cout);
    virtual ~CheckSuit();

    std::string execute(Entity* affected);
    ObjectBlueprint* makeBlueprint() const;

    Room* getHere();

  protected:
    Room* here;

  private:
    CheckSuit(const CheckSuit& other);
    CheckSuit& operator=(const CheckSuit& other);
};

#endif // CHECKSUIT_H
