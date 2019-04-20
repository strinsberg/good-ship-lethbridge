/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_PLAYER_H
#define CALRISSIEN_2720_PLAYER_H

#include "Container.h"
#include "Room.h"
#include "ObjectBlueprint.h"
#include "Suit.h"
#include <string>


/**
  * The player character
  */
class Player : public Container {
 public:
  Player();
  Player(std::string id) : Container(id) {}
  virtual ~Player();
  virtual std::string describe() const;

  /**
    * Returns the room the player is currently in. Does not transfer ownership.
    * @return the room the player is in
    */
  Room* getCurrentRoom() const;

  /**
    * Set the players current Room. Does not transfer ownership.
    * @param r the room the player is now in
    */
  void setCurrentRoom(Room* r);

  /**
    * Puts on the given suit. Transfers ownership so it must be removed
    * from wherever it is before being equipped. If there is a currently
    * equipped suit it will be removed and put in the players inventory.
    * @param suit the suit to equip.
    */
  void wearSuit(Suit* suit);

  /**
    * Returns the suit that is currently equipped or nullptr if
    * no suit is equipped. Does not transfer ownership.
    * @return the quipped suit.
    */
  Suit* getSuit();

  /**
    * Takes off the currently equipped suit, if applicable, and puts it in
    * the players inventory.
    */
  void removeSuit();

 private:
  Room* currentRoom;  // does not own the room
  Suit* suit;  // owns this

  Player(const Player&);
  Player& operator=(const Player&);
};

#endif // PLAYER_H
