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
  virtual ~Player();
  virtual std::string describe() const;
  virtual std::string use(Entity*);
  virtual ObjectBlueprint* makeBlueprint() const;

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
    * Sets the suit that the player is wearing. Does not transfer ownership.
    * should not be set unless the suit is in the players inventory as well.
    * suit is owned by the players inventory.
    * @param s the new equipped suit.
    */
  void setEquipped(Suit* s);

  /**
    * Returns the suit that is currently equipped or nullptr if
    * no suit is equipped. Does not transfer ownership.
    * @return the quipped suit.
    */
  Suit* getEquipped();

 private:
  Room* currentRoom;  // does not own the room
  Suit* equipped;  // does not own this
  Player(const Player&);
  Player& operator=(const Player&);
};

#endif // PLAYER_H
