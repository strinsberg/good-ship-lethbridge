/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */
#ifndef SUIT_H
#define SUIT_H

#include"Atmosphere.h"
#include"Entity.h"

class Suit :public Entity {
public:
Suit();
~Suit();
string describe() const;
string use(Entity* user);
ObjectBlueprint* makeBlueprint() const;
Atmosphere getAtmosphere();
void setAtmosphere(Atmosphere a);
private:
  Atmosphere atmosphere;
};


#endif // SUIT_H
