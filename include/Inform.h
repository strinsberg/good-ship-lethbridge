/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#ifndef INFORM_H
#define INFORM_H

#include "Event.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>

/**
  * An event to return information
  */
class Inform : public Event
{
  public:
    /**
      * Create an inform object with in and out streams
      * @param in an istream (default cin)
      * @param out an ostream (default cout)
      */
    Inform(std::istream& in = std::cin, std::ostream& out = std::cout);
    virtual ~Inform();

    std::string execute(std::vector<Entity*>& affected);
    ObjectBlueprint* makeBlueprint() const;

  private:
    Inform(const Inform& other);
    Inform& operator=(const Inform& other);
};

#endif // INFORM_H
