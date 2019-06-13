#ifndef ENTITYCONNECTOR_H
#define ENTITYCONNECTOR_H

#include "Visitor.h"
#include "Event.h"
#include "Entity.h"
#include "json.h"

class Entity;
class Container;
using json = nlohmann::json;

class EntityConnector : public Visitor {
  public:
    EntityConnector(json obj, std::map<std::string, Entity*>&, std::map<std::string, Event*>&);
    virtual ~EntityConnector();

    void visit(Entity*);
    void visit(Container*);

  private:
    json object;
    std::map<std::string, Entity*>& entities;
    std::map<std::string, Event*>& events;

    void connectEvents(Entity* e);

    EntityConnector(const EntityConnector& other);
    EntityConnector& operator=(const EntityConnector& other);
};

#endif // ENTITYCONNECTOR_H
