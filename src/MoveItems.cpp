#include "MoveItems.h"
#include "ObjectBlueprint.h"
#include "Container.h"
#include "Exceptions.h"

MoveItems::MoveItems(Entity* o, std::string name, std::istream& is, std::ostream& os)
    : Event(is, out), owner(o), itemName(name), give(false) {}

MoveItems::~MoveItems() {}

std::string MoveItems::execute(Entity* affected) {
  if (spec->isDone())
    return "";

  if (Container* own = dynamic_cast<Container*>(owner)) {
      if (Container* aff = dynamic_cast<Container*>(affected)) {
        if (give) {
          Entity* e = own->search(itemName);
          own->removeEntity(e);
          aff->addEntity(e);
          spec->setDone(true);
          return owner->getSpec()->getName() + " gives you a " + itemName;
        } else {
          Entity* e = aff->search(itemName);
          aff->removeEntity(e);
          own->addEntity(e);
          spec->setDone(true);
          return "You give a " + itemName + " to " + owner->getSpec()->getName();
        }
      }
    throw unfinished_object_error("Move items event is not attached to a container!");
  }
}

ObjectBlueprint* MoveItems::makeBlueprint() const {}

Entity* MoveItems::getOwner() const {
  return owner;
}

std::string MoveItems::getItemName() {
  return itemName;
}

void MoveItems::setGive(bool g) {
  give = g;
}

bool MoveItems::isGive() {
  return give;
}