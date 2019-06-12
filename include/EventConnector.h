#ifndef EVENTCONNECTOR_H
#define EVENTCONNECTOR_H

#include "Visitor.h"
#include "Event.h"
#include "TransferItem.h"
#include "Inform.h"
#include "ToggleActive.h"
#include "EventGroup.h"
#include "Conditional.h"
#include "ConditionalEvent.h"
#include "Interaction.h"
#include "json.h"

class Event;
using json = nlohmann::json;


class EventConnector : public Visitor
{
    public:
        EventConnector(json obj, std::map<std::string, Event*>, std::map<std::string, Conditional*>, std::map<std::string, Entity*>);
        virtual ~EventConnector();

        void visit(Inform*);
        void visit(TransferItem*);
        void visit(EventGroup*);
        void visit(ToggleActive*);
        void visit(ConditionalEvent* c);
        void visit(Interaction*);

    private:
        json object;
        std::map<std::string, Event*> events;
        std::map<std::string, Conditional*> conditions;
        std::map<std::string, Entity*> entities;

        void connectSubjects(Event* e);

        EventConnector(const EventConnector& other);
        EventConnector& operator=(const EventConnector& other);
};

#endif // EVENTCONNECTOR_H
