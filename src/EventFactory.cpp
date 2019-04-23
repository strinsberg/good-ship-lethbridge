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
#include "ToggleActive.h"
#include "Door.h"
#include "MovePlayer.h"
#include "EquipSuit.h"
#include "Conditional.h"
#include "Question.h"
#include "Protected.h"
#include "HasItem.h"
#include "Atmosphere.h"
#include <string>
#include <iostream>

bool stob(const std::string& str) {
  return str == "true";
}

Atmosphere sToAtmos(std::string& str) {
  if (str == "radiation")
    return Atmosphere::RADIATION;
  else if (str == "space")
    return Atmosphere::SPACE;
  else
    return Atmosphere::OXYGEN;
}

EventFactory::EventFactory(std::vector<ObjectBlueprint*>& blue,
                           std::map<std::string, Room*>& rms)
    : blueprints(blue), rooms(rms), events(std::map<std::string, Event*>()) {}

EventFactory::~EventFactory() {}

void EventFactory::makeEvents() {
  // Convert the blueprints into objects
  for (auto bp : blueprints) {
    Event* event = nullptr;
    std::string type = bp->getType();
    if (type == "inform")
      event = makeInform(bp);
    else if (type == "kill")
      event = makeKill(bp);
    else if (type == "transfer")
      event = makeTransferItem(bp);
    else if (type == "toggle")
      event = makeToggleActive(bp);
    else if (type == "moveplayer")
      event = makeMovePlayer(bp);
    else if (type == "equipsuit")
      event = makeEquipSuit(bp);
    else if (type == "group")
      event = makeEventGroup(bp);
    else if (type == "structured")
      event = makeStructuredEvent(bp);
    else if (type == "interaction")
      event = makeInteraction(bp);
    else if (type == "conditionalevent")
      event = makeConditionalEvent(bp);
    else if (type == "condition")
      makeCondition(bp);
    else
      throw unfinished_object_error("Error: Event type not found! ID: " + bp->getField("id") + " Type: " + type);

    // Add to events map for easy lookup while building
    if (type != "condition") {
      std::string oneTime = bp->getField("once");
      if (oneTime != ObjectBlueprint::null()) {
        bool once = stob(oneTime);
        event->setOnce(once);
      }
      events[bp->getField("id")] = event;
    }
  }

  // Go through and deal with all subscriptions
  // requires all events to be created
  for (auto bp : blueprints) {
    std::string subjectId = bp->getField("subject");
    if (subjectId != ObjectBlueprint::null()) {
      Event* subject = events.find(subjectId)->second;
      Event* observer = events.find(bp->getField("id"))->second;
      subject->subscribe(observer);
    }
  }
}

// Base Events
Event* EventFactory::makeInform(ObjectBlueprint* bp) {
  Inform* inf = new Inform(bp->getField("id"), bp->getField("message"));
  addToOwner(inf, bp);
  return inf;
}

Event* EventFactory::makeKill(ObjectBlueprint* bp) {
  Kill* k = new Kill(bp->getField("id"), bp->getField("message"), stob(bp->getField("ending")));
  addToOwner(k, bp);
  return k;
}

Event* EventFactory::makeTransferItem(ObjectBlueprint* bp) {
  std::string other = bp->getField("other");
  Entity* ent = findEntity(other);

  Container* con = dynamic_cast<Container*>(ent);
  bool toTarget = stob(bp->getField("totarget"));
  TransferItem* ti = new TransferItem(bp->getField("id"), con, bp->getField("itemid"), toTarget);

  addToOwner(ti, bp);
  return ti;
}

Event* EventFactory::makeToggleActive(ObjectBlueprint* bp) {
  std::string target = bp->getField("target");
  Entity* ent = findEntity(target);

  bool once = stob(bp->getField("once"));
  ToggleActive* tog = new ToggleActive(bp->getField("id"), ent, once);

  addToOwner(tog, bp);
  return tog;
}

Event* EventFactory::makeMovePlayer(ObjectBlueprint* bp) {
  std::string doorId = bp->getField("door");
  Entity* ent = findEntity(doorId);

  Door* door = dynamic_cast<Door*>(ent);
  MovePlayer* mp = new MovePlayer(bp->getField("id"), door);

  addToOwner(mp, bp);
  return mp;
}

Event* EventFactory::makeEquipSuit(ObjectBlueprint* bp) {
  std::string suitId = bp->getField("suit");
  Entity* ent = findEntity(suitId);

  Suit* suit = dynamic_cast<Suit*>(ent);
  EquipSuit* es = new EquipSuit(bp->getField("id"), suit);

  addToOwner(es, bp);
  return es;
}


// Composite events
Event* EventFactory::makeEventGroup(ObjectBlueprint* bp) {
  EventGroup* eg = new EventGroup(bp->getField("id"));
  addToOwner(eg, bp);
  return eg;
}

Event* EventFactory::makeStructuredEvent(ObjectBlueprint* bp) {
  bool repeats = stob(bp->getField("repeats"));
  StructuredEvents* se = new StructuredEvents(bp->getField("id"), repeats);
  addToOwner(se, bp);
  return se;
}

Event* EventFactory::makeInteraction(ObjectBlueprint* bp) {
  Interaction* inter = new Interaction(bp->getField("id"));
  bool breakout = stob(bp->getField("breakout"));
  inter->setBreakout(breakout);
  addToOwner(inter, bp);
  return inter;
}

Event* EventFactory::makeConditionalEvent(ObjectBlueprint* bp) {
  ConditionalEvent* ce = new ConditionalEvent(bp->getField("id"));
  addToOwner(ce, bp);
  return ce;
}

void EventFactory::makeCondition(ObjectBlueprint* bp) {
  Conditional* cond;
  std::string subtype = bp->getField("subtype");
  std::string id = bp->getField("id");
  if (subtype == "question") {
    cond = new Question(bp->getField("question"), bp->getField("answer"));
  } else if (subtype == "protected") {
    std::string atmos = bp->getField("atmosphere");
    Atmosphere atmosphere = sToAtmos(atmos);
    cond = new Protected(atmosphere);
  } else if (subtype == "hasitem") {
    cond = new HasItem(bp->getField("itemid"));
  } else {
    throw unfinished_object_error("Error: conditional doens't have valid subtype! ID: " + id + " subtype: " + subtype);
  }

  Event* event = events.find(bp->getField("event"))->second;
  ConditionalEvent* owner = dynamic_cast<ConditionalEvent*>(event);
  owner->setCondition(cond);
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
    std::string ownerType = bp->getField("ownertype");

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
