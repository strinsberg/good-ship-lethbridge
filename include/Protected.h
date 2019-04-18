#ifndef PROTECTED_H
#define PROTECTED_H

#include "Conditional.h"
#include "Atmosphere.h"

class Protected : public Conditional
{
  public:
    Protected(Atmosphere atmosphere);
    virtual ~Protected();

    /**
      * Tests to see if the target is protected from the atmosphere
      * @param target the entity to check
      * @return true if the entity is protected
      */
    bool test(Entity* target) const;

  private:
    Atmosphere atmosphere;

    Protected(const Protected& other);
    Protected& operator=(const Protected& other);
};

#endif // PROTECTED_H
