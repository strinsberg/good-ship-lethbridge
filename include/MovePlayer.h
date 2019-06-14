#ifndef MOVEPLAYER_H
#define MOVEPLAYER_H

#include "Event.h"
#include "EventVisitor.h"
#include "Door.h"
#include <string>


class MovePlayer : public Event {
  public:
    MovePlayer(std::string id)
        : Event(id), door(nullptr), destination(nullptr) {}
    MovePlayer(std::string id, Door* mover);
    virtual ~MovePlayer();

    std::string execute(Entity* target);

    void setDestination(Room* d) {destination = d;}

    void accept(EventVisitor& v) {
        v.visit(this);
    }

  protected:
    Door* door;
    Room* destination;

  private:
    MovePlayer(const MovePlayer& other);
    MovePlayer& operator=(const MovePlayer& other);
};

#endif // MOVEPLAYER_H
