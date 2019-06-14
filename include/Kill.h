/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef KILL_H
#define KILL_H

#include "Inform.h"
#include "EventVisitor.h"
#include <string>

/**
  * An event to kill an entity. Sets the entities hidden value to true.
  */
class Kill : public Inform {
  public:
    Kill(std::string id, std::string message, bool isEnd=false);
    virtual ~Kill();
    std::string execute(Entity* affected);

    virtual void accept(EventVisitor& v);

  private:
    bool ending;

    Kill(const Kill& other);
    Kill& operator=(const Kill& other);
};

#endif // KILL_H
