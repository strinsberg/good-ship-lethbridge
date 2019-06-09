#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Visitor.h"
#include "json.h"

using json = nlohmann::json;


class Connector : public Visitor
{
    public:
        Connector(json obj) : object(obj) {}
        virtual ~Connector() {}

        virtual void collect() {}

    private:
        json object;

        Connector(const Connector& other);
        Connector& operator=(const Connector& other);
};

#endif // CONNECTOR_H
