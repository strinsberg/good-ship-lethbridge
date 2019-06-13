/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-17
 */

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

/**
  * An interface for game components that need to save information.
  */
class Serializable {
  public:
    Serializable() {}
    virtual ~Serializable() {}

    virtual void serialize(std::ostream&) = 0;
};

#endif // SERIALIZABLE_H
