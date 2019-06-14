#ifndef EVENTVISITOR_H
#define EVENTVISITOR_H

class Event;
class Inform;
class Kill;
class ToggleActive;
class TransferItem;
class MovePlayer;
class EventGroup;
class StructuredEvents;
class ConditionalEvent;
class Interaction;

class EventVisitor
{
  public:
    EventVisitor() {}
    virtual ~EventVisitor() {}

    virtual void visit(Event* v) {}
    virtual void visit(Inform*) = 0;
    virtual void visit(Kill*) = 0;
    virtual void visit(ToggleActive*) = 0;
    virtual void visit(TransferItem*) = 0;
    virtual void visit(MovePlayer*) = 0;
    virtual void visit(EventGroup*) = 0;
    virtual void visit(StructuredEvents*) = 0;
    virtual void visit(ConditionalEvent*) = 0;
    virtual void visit(Interaction*) = 0;

  private:
    EventVisitor(const EventVisitor&);
    EventVisitor& operator=(const EventVisitor&);
};

#endif // EVENTVISITOR_H
