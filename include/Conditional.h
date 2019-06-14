#ifndef DGSL_CONDITIONAL_H
#define DGSL_CONDITIONAL_H

#include "Entity.h"

/**
  * Base class for a condition that an entity can be tested for.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>
  * @date 2019-04-19
  */
class Conditional {
  public:
    Conditional(std::string ID) : id(ID) {}
    virtual ~Conditional() {}

    /**
      * Test the given entity for some condition and return true
      * if they satisfy it. Does not transfer ownership.
      * @param target the entity to test.
      * @return true if the entity satisfies the condition, otherwise false.
      */
    virtual bool test(Entity* target) const = 0;

    void setId(std::string ID) {
        id = ID;
    }
    std::string getId() {
        return id;
    }

  private:
    std::string id;

    Conditional(const Conditional&);
    Conditional& operator=(const Conditional&);
};

#endif // CONDITIONAL_H
