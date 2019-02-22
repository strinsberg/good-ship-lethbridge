/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_ROOM_H
#define CALRISSIEN_2720_ROOM_H

#include "Entity.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"


/**
  * Base class for all areas of the game
  */
class Room : public Container {
 public:
  Room();
  virtual ~Room();
  void describe();
  void use(Entity&);
  void serialize(std::fstream&);

  /**
    * Take action when an entity enters the room
    * @param entity the entity entering the room
    */
  virtual void enter(Entity& entity);

  /**
    * Take action when an entity leaves the room
    * @param entity the entity leaving the room
    */
  virtual void exit(Entity& entity);

  /**
    * Set an event to execute when the room is entered. Transfers ownership
    * to this room.
    * @param event the event
    */
  void setEnter(Event* event);

  /**
    * Set an event to execute when the room is exited. Transfers ownership
    * to this room.
    * @param event the event
    */
  void setExit(Event*);

 protected:
  Atmosphere atmosphere;
  Event* enterEvent;  // owns these events
  Event* exitEvent;

 private:
  Room(const Room&);
  Room operator=(const Room&);
};

#endif // ROOM_H
