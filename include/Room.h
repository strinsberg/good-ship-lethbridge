/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_ROOM_H
#define CALRISSIEN_2720_ROOM_H

#include "Entity.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include <string>


/**
  * Base class for all areas of the game
  */
class Room : public Container {
 public:
  Room(std::string id);
  virtual ~Room();
  virtual std::string describe() const;

  /**
    * Take action when an entity enters the room. Does not transfer ownership to Room.
    * @param entity the entity entering the room
    */
  virtual std::string enter(Entity* entity);

  /**
    * Return the atmosphere of the room.
    * @return the atmosphere of the room
    */
  Atmosphere getAtmosphere();

  /**
    * Set the atmosphere of the room.
    * @param a the new value of the rooms atmosphere.
    */
  void setAtmosphere(Atmosphere a);

 protected:
  Atmosphere atmosphere;

 private:
  Room(const Room&);
  Room& operator=(const Room&);
};

#endif // ROOM_H
