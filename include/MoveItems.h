#ifndef MOVEITEMS_H
#define MOVEITEMS_H

#include "Event.h"
#include "ObjectBlueprint.h"

class MoveItems : public Event
{
  public:
    MoveItems(Entity* owner, std::string itemName, std::istream& is = std::cin, std::ostream& os = std::cout);
    virtual ~MoveItems();

    std::string execute(Entity* e);
    ObjectBlueprint* makeBlueprint() const;

    Entity* getOwner() const;
    std::string getItemName();
    bool isGive();
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
