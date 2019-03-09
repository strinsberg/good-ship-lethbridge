#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"

EntityState::EntityState():obtainable(true),active(true),hidden(false){}

EntityState::~EntityState(){}

bool EntityState::getObtainable() const{
return obtainable;
}

void EntityState::setObtainable(bool ob) {
  obtainable=ob;
}

bool EntityState::getActive() const {
return active;
}

void EntityState::setActive(bool a) {
active=a;
}

bool EntityState::getHidden() const {
return hidden;
}

void EntityState::setHidden(bool h) {
hidden = h;
}
