/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "OwnedEvent.h"
#include "Entity.h"
#include <string>

OwnedEvent::OwnedEvent(std::string ID, Entity* own)
    : Event(ID), owner(own) {}

OwnedEvent::~OwnedEvent() {}

