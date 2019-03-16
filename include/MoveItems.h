/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-03-16
 */

#ifndef MOVEITEMS_H
#define MOVEITEMS_H

#include "Event.h"
#include "ObjectBlueprint.h"
#include <string>


/**
  * An event that will move items between the owner and the user. The
  * direction of the movement depends on the object. (default is to give
  * move from the user to the owner of the event)
  */
class MoveItems : public Event {
 public:
  /**
    * Create an event that will move items between the owner and the user.
    * @param owner the owner of the event
    * @param itemName the name of the item to be moved.
    * @param in an istream (default cin)
    * @param out an ostream (default cout)
    */
  MoveItems(Entity* owner, std::string itemName, std::istream& is = std::cin,
            std::ostream& os = std::cout);

  virtual ~MoveItems();
  std::string execute(Entity* e);
  ObjectBlueprint* makeBlueprint() const;

  /**
    * Get the owner of the event. Does not transfer ownership.
    * @return a pointer to the owner of the event.
    */
  Entity* getOwner() const;

  /**
    * Return the name of the item to be moved
    * @return ItemName
    */
  std::string getItemName();

  /**
    * Return if the event gives items to the player or takes them
    * @return true if the item moves from the owner to the player
    */
  bool isGive();

  /**
    * Set the if the item is given to the player or taken
    * @param g the new value of give
    */
  void setGive(bool g);

 protected:
  Entity* owner;  // doe not own
  std::string itemName;
  bool give;  // if the item is being given to the affected entity

 private:
  MoveItems(const MoveItems& other);
  MoveItems& operator=(const MoveItems& other);
};

#endif // MOVEITEMS_H
