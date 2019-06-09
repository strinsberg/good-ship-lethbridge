#ifndef ENTITYCONNECTOR_H
#define ENTITYCONNECTOR_H

#include "Connector.h"
#include "Event.h"
#include "json.h"

class Entity;
class Container;
using json = nlohmann::json;

class EntityConnector : public Connector
{
    public:
        EntityConnector(json obj);
        virtual ~EntityConnector();

        void collect(std::map<std::string, Entity*>, std::map<std::string, Event*>);
        void visit(Entity*);
        void visit(Container*);

    private:
        EntityConnector(const EntityConnector& other);
        EntityConnector& operator=(const EntityConnector& other);
};

#endif // ENTITYCONNECTOR_H
