#ifndef ENTITYCONNECTOR_H
#define ENTITYCONNECTOR_H

#include "EntityVisitor.h"
#include "json.h"

using json = nlohmann::json;

class Event;
class Entity;
class Container;
class Room;
class Npc;
class Suit;
class Player;


class EntityConnector : public EntityVisitor {
  public:
    EntityConnector(json obj, std::map<std::string, Entity*>&, std::map<std::string, Event*>&);
    virtual ~EntityConnector();

    virtual void visit(Entity*);
    virtual void visit(Suit*);
    virtual void visit(Container*);
    virtual void visit(Room*);
    virtual void visit(Npc*);
    virtual void visit(Player*);

  private:
    json object;
    std::map<std::string, Entity*>& entities;
    std::map<std::string, Event*>& events;

    void connectEvents(Entity* e);
    void connectItems(Container* e);

    EntityConnector(const EntityConnector& other);
    EntityConnector& operator=(const EntityConnector& other);
};

#endif // ENTITYCONNECTOR_H
