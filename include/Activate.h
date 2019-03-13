#ifndef ACTIVATE_H
#define ACTIVATE_H

#include "Event.h"


class Activate : public Event
{
  public:
    Activate(Entity* t, std::istream& is = std::cin, std::ostream& os = std::cout);
    virtual ~Activate();
    virtual std::string execute(Entity* e);
    virtual ObjectBlueprint* makeBlueprint() const;

    /**
      * Set the entity to activate
      * @param e the target entity
      */
    void setTarget(Entity* e);

    /**
      * Get the target entity
      * @return target
      */
    Entity* getTarget();

  protected:
    Entity* target;

  private:
    Activate(const Activate& other);
    Activate& operator=(const Activate& other);
};

#endif // ACTIVATE_H
