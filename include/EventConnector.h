#ifndef EVENTCONNECTOR_H
#define EVENTCONNECTOR_H

#include "Connector.h"
#include "json.h"

class Event;
using json = nlohmann::json;


class EventConnector : public Connector
{
    public:
        EventConnector(json obj);
        virtual ~EventConnector();

        void collect(std::map<std::string, Event*>, std::map<std::string, Conditional*>);
        void visit(Event*);

    private:
        EventConnector(const EventConnector& other);
        EventConnector& operator=(const EventConnector& other);
};

#endif // EVENTCONNECTOR_H
