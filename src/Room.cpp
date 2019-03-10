/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Room.h"
#include "Entity.h"
#include "Container.h"
#include "Atmosphere.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "Exceptions.h"
#include <string>

Room::Room() : atmosphere(Atmosphere::OXYGEN),
               enterEvent(nullptr),
               exitEvent(nullptr) {}

Room::~Room() {
  if (enterEvent != nullptr)
    delete enterEvent;
  if (exitEvent != nullptr)
    delete exitEvent;
}

std::string Room::describe() {
  if (spec == nullptr)
    throw(unfinished_object_error("The room has no spec!"));
  return spec->getDescription();
}

std::string Room::use(Entity*) {
  return "You can't use a room!";
}

ObjectBlueprint* Room::makeBlueprint() const {

}

std::string Room::enter(Entity* entity) {
  if (enterEvent == nullptr)
    return "";
  return enterEvent->execute(entity);
}

std::string Room::exit(Entity* entity) {
  if (exitEvent == nullptr)
    return "";
  return exitEvent->execute(entity);
}

void Room::setEnter(Event* event) {
  enterEvent = event;
}

void Room::setExit(Event* event) {
  exitEvent = event;
}