/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-21
 */

#include "EventFactory.h"
#include "Exceptions.h"
#include "Inform.h"
#include "Kill.h"
#include "Interaction.h"
#include "EventGroup.h"
#include "StructuredEvents.h"
#include "ConditionalEvent.h"
#include "TransferItem.h"

bool stob(const std::string& str) {
  return str == "true";
}

EventFactory::EventFactory(std::vector<ObjectBlueprint*>& blue,
                           std::map<std::string, Room*>& rms)
    : blueprints(blue), rooms(rms), events(std::map<std::string, Event*>()) {}

EventFactory::~EventFactory() {}

void EventFactory::makeEvents() {
  // for each blueprint make an event
  // add it to the events map
  for (auto bp : blueprints) {
    Event* event;
    std::string type = bp->getType();
    if (type == "inform")
      event = makeInform(bp);
    else if (type == "kill")
      event = makeKill(bp);
    else
      throw unfinished_object_error("Error: Event type not found! ID: " + bp->getField("id") + " Type: " + type);
    // Add to events map for easy lookup while building
    events[bp->getField("id")] = event;
  }

  // Go through and deal with all subscriptions
}

// Base Events
Event* EventFactory::makeInform(ObjectBlueprint* bp) {
  std::string id = bp->getField("id");
  Inform* inf = new Inform(id, bp->getField("message"));
  addToOwner(inf, bp);
  return inf;
}

Event* EventFactory::makeKill(ObjectBlueprint* bp) {
  Kill* k = new Kill(bp->getField("id"), bp->getField("message"));
  addToOwner(k, bp);
  return k;
}

Event* EventFactory::makeTransferItem(ObjectBlueprint* bp) {
  std::string other = bp->getField("owner");
  Entity* ent = findEntity(other);

  Container* con = dynamic_cast<Container*>(ent);
  bool toTarget = stob(bp->getField("totarget"));
  TransferItem* ti = new TransferItem(bp->getField("id"), con, bp->getField("itemId"), toTarget);

  addToOwner(ti, bp);
  return ti;
}

Event* EventFactory::makeToggleActive(ObjectBlueprint* bp) {

}

Event* EventFactory::makeMovePlayer(ObjectBlueprint* bp) {

}

Event* EventFactory::makeEquipSuit(ObjectBlueprint* bp) {

}


// Composite events
Event* EventFactory::makeEventGroup(ObjectBlueprint* bp) {

}

Event* EventFactory::makeStructuredEvent(ObjectBlueprint* bp) {

}

Event* EventFactory::makeInteraction(ObjectBlueprint* bp) {

}

Event* EventFactory::makeConditionalEvent(ObjectBlueprint* bp) {

}

// Private ///////////////////////////////////////////////////////////////////

Entity* EventFactory::findEntity(std::string entityId) {
  for (auto it : rooms) {
    if (it.second->getSpec()->getId() == entityId)
      return it.second;

    Entity* ent = it.second->searchById(entityId);
    if (ent != nullptr) {
      return ent;
    }
  }
  return nullptr;
}

void EventFactory::addToOwner(Event* event, ObjectBlueprint* bp) {
  std::string ownerId = bp->getField("entity");
  // If there is an entity owner
  if (ownerId != ObjectBlueprint::null()) {
    // Search all rooms until you find the entity and add the event to it
    for (auto it : rooms) {
      Entity* ent = it.second->searchById(ownerId);
      if (ent != nullptr) {
        ent->addEvent(bp->getField("verb"), event);
        break;
      }
    }
  // If the event is part of a composite event
  } else {
    ownerId = bp->getField("event");
    std::string ownerType = bp->getField("ownerType");

    auto it = events.find(ownerId);
    if (ownerType == "interaction") {
      Interaction* in = dynamic_cast<Interaction*>(it->second);
      in->addOption(bp->getField("optiontext"), event);
    } else if (ownerType == "conditional") {
      ConditionalEvent* con = dynamic_cast<ConditionalEvent*>(it->second);
      if (bp->getField("condition") == "success")
        con->setSuccess(event);
      else
        con->setFailure(event);
    } else {
      EventGroup* eg = dynamic_cast<EventGroup*>(it->second);
      eg->addEvent(event);
    }
  }
}
