/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-21
 */

#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "ObjectBlueprint.h"
#include "Room.h"
#include "Event.h"
#include <vector>
#include <map>
#include <string>

class EventFactory
{
  public:
    EventFactory(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);
    virtual ~EventFactory();

    void makeEvents();

    // Base Events
    Event* makeInform(ObjectBlueprint* bp);
    Event* makeKill(ObjectBlueprint* bp);
    Event* makeTransferItem(ObjectBlueprint* bp);
    Event* makeToggleActive(ObjectBlueprint* bp);
    Event* makeMovePlayer(ObjectBlueprint* bp);
    Event* makeEquipSuit(ObjectBlueprint* bp);

    // Composite events
    Event* makeEventGroup(ObjectBlueprint* bp);
    Event* makeStructuredEvent(ObjectBlueprint* bp);
    Event* makeInteraction(ObjectBlueprint* bp);
    Event* makeConditionalEvent(ObjectBlueprint* bp);

  protected:
    std::vector<ObjectBlueprint*>& blueprints;
    std::map<std::string, Room*>& rooms;
    std::map<std::string, Event*> events;

  private:
    void addToOwner(Event* event, ObjectBlueprint* bp);

    EventFactory(const EventFactory& other);
    EventFactory& operator=(const EventFactory& other);
};

#endif // EVENTFACTORY_H
