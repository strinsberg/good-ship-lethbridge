/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#include "StructuredEvents.h"
#include "ObjectBlueprint.h"
#include "ObjectWithContentsBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>

StructuredEvents::StructuredEvents(std::string id, bool re)
    : EventGroup(id), currentEvent(0), repeats(re) {}

StructuredEvents::~StructuredEvents() {}

std::string StructuredEvents::execute(Entity* affected) {
    if (currentEvent == events.size()) {
        if (repeats)
            currentEvent = 0;
        else
            return events[events.size()-1]->execute(affected);
    }

    return events[currentEvent++]->execute(affected);
}
