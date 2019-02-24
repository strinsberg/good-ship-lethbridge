/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_PLAYER_H
#define CALRISSIEN_2720_PLAYER_H

#include "Container.h"
#include "Room.h"
#include "ObjectBlueprint.h"
#include <string>


/**
  * The player character
  */
class Player : public Container {
 public:
  Player();
  virtual ~Player();
  virtual std::string describe() const;
  virtual std::string use(Entity&);
  virtual ObjectBlueprint* makeBlueprint() const;

  /**
    * @return the room the player is in
    */
  Room& getCurrentRoom() const;

  /**
    * @param room the room the player is now in
    */
  void setCurrentRoom(Room*);

 private:
  Room* currentRoom;  // does not own the room

  Player(const Player&);
  Player& operator=(const Player&);
};

#endif // PLAYER_H
