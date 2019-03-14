/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */
#include"Suit.h"
#include"Player.h"
#include "ObjectBlueprint.h"
#include<typeinfo>

Suit::Suit(){}
Suit::~Suit(){}

string Suit::describe() const{
return spec->getDescription();
}
string Suit::use(Entity* user){

  if(Player* p = dynamic_cast<Player*>(user)) {
    p->setEquipped(this);
    return "the suit is on you";
  }

  return "suit authorization failed";
}

ObjectBlueprint* Suit::makeBlueprint() const{
  ObjectBlueprint* bp = Entity::makeBlueprint();
  bp->setField("type", "suit");
  bp->setField("atmosphere", std::to_string(atmosphere));
  return bp;
}

Atmosphere Suit::getAtmosphere(){
return atmosphere;
}

void Suit::setAtmosphere(Atmosphere a){
atmosphere = a;
}
