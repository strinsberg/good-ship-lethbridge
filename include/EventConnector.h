#ifndef EVENTCONNECTOR_H
#define EVENTCONNECTOR_H

#include "EventVisitor.h"
#include "json.h"

class Event;
class Conditional;
class Entity;
class Inform;
class Kill;
class ToggleActive;
class TransferItem;
class MovePlayer;
class EventGroup;
class StructuredEvents;
class ConditionalEvent;
class Interaction;

using json = nlohmann::json;


class EventConnector : public EventVisitor {
  public:
    EventConnector(json obj, std::map<std::string, Event*>, std::map<std::string, Conditional*>, std::map<std::string, Entity*>);
    virtual ~EventConnector();

    virtual void visit(Inform*);
    virtual void visit(Kill*);
    virtual void visit(ToggleActive*);
    virtual void visit(TransferItem*);
    virtual void visit(MovePlayer*);
    virtual void visit(EventGroup*);
    virtual void visit(StructuredEvents*);
    virtual void visit(ConditionalEvent*);
    virtual void visit(Interaction*);

  private:
    json object;
    std::map<std::string, Event*> events;
    std::map<std::string, Conditional*> conditions;
    std::map<std::string, Entity*> entities;

    void connectSubjects(Event* e);
    void connectEvents(EventGroup* e);

    EventConnector(const EventConnector& other);
    EventConnector& operator=(const EventConnector& other);
};

#endif // EVENTCONNECTOR_H
