/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Entity.h"

class Conditional
{
  public:
    Conditional() {}
    virtual ~Conditional() {}

    /**
      * Test the given entity for some condition and return true
      * if they satisfy it. Does not transfer ownership.
      * @param target the entity to test
      */
    virtual bool test(Entity* target) const = 0;

  private:
    Conditional(const Conditional&);
    Conditional& operator=(const Conditional&);
  };

#endif // CONDITIONAL_H
