/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef DOOR_H
#define DOOR_H

#include "Entity.h"
#include "Room.h"
#include "Game.h"
#include <string>

/**
  * An object that leads to another room.
  */
class Door : public Entity {
 public:
  Door();
  Door(std::string id);
  virtual ~Door();
  virtual std::string describe() const;

  /**
    * Set a destination for the door to lead to.
    * @param room the destination room
    */
  void setDestination(Room* room);

  /**
    * Get the room the door leads to
    * @return destination
    */
  Room* getDestination();

  /**
    * Set a location of the door
    * @param room the location of the room
    */
  void setHere(Room* room);

  /**
    * Get the room the door is in
    * @return here
    */
  Room* getHere();

 private:
  Room* destination;  // Does not own this
  Room* here;  // does not own this

  struct MoveEntity : public Event {
    MoveEntity(std::string id, Room* h, Room* t) : Event(id), here(h), there(t) {}
    std::string execute(Entity* e) {
      there->addEntity(here->searchAndRemove(Game::toLower(e->getSpec()->getId())));
    }
    Room* here;
    Room* there;
  };

  Door(const Door& other);
  Door& operator=(const Door& other);
};

#endif // DOOR_H
