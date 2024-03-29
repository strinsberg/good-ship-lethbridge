/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
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
class Inform : public Event {
 public:
  /**
    * Create an Inform object with in and out streams
    * @param in an istream (default cin)
    * @param out an ostream (default cout)
    */
  Inform(std::istream& is = std::cin, std::ostream& os = std::cout);

  virtual ~Inform();
  std::string execute(Entity* affected);
  ObjectBlueprint* makeBlueprint() const;

 private:
  Inform(const Inform& other);
  Inform& operator=(const Inform& other);
};

#endif // INFORM_H
