/**
* @author
*
*/
#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"


Entity::Entity():spec(nullptr),state(nullptr),event(nullptr){}

Entity::~Entity(){
delete spec;
delete state;
delete event;
}

EntitySpec* Entity::getSpec() const {

  return spec;
}

void Entity::setSpec(EntitySpec* s){
  spec = s;
}

EntityState* Entity::getState() const{
 return state;
}

void Entity::setEvent(Event* e){
event = e;
}

Event* Entity::getEvent() const{
return event;
}
