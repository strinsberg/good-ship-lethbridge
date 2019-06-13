/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef STRUCTUREDEVENTS_H
#define STRUCTUREDEVENTS_H

#include "EventGroup.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>


/**
  * A collection of sequenced events when execute is
  * called the next current events execute is called.
  * Can be set to repeat when the last event is reached
  * or it just repeats the final event every time it is
  * executed.
  */
class StructuredEvents : public EventGroup {
  public:
    StructuredEvents(std::string id, bool repeats=false);
    virtual ~StructuredEvents();
    std::string execute(Entity* affected);

  private:
    int currentEvent;
    bool repeats;

    StructuredEvents(const StructuredEvents& other);
    StructuredEvents& operator=(const StructuredEvents& other);
};

#endif // STRUCTUREDEVENTS_H
