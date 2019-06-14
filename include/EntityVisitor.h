#ifndef VISITOR_H
#define VISITOR_H

class Entity;
class Container;
class Room;
class Npc;
class Suit;
class Player;

class EntityVisitor {
  public:
    EntityVisitor() {}
    virtual ~EntityVisitor() {}

    virtual void visit(Entity*) = 0;
    virtual void visit(Container*) = 0;
    virtual void visit(Room*) = 0;
    virtual void visit(Suit*) = 0;
    virtual void visit(Npc*) = 0;
    virtual void visit(Player*) = 0;

  private:
    EntityVisitor(const EntityVisitor&);
    EntityVisitor& operator=(const EntityVisitor&);
};

#endif // VISITOR_H
