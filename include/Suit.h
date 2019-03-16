/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */


#ifndef SUIT_H
#define SUIT_H

#include"Atmosphere.h"
#include"Entity.h"
#include <string>


/**
  * A suit that if equipped will protect a player from an environment
  * that they might be in.
  */
class Suit :public Entity {
 public:
  Suit();
  ~Suit();
  std::string describe() const;
  std::string use(Entity* user);
  ObjectBlueprint* makeBlueprint() const;

  /**
    * Return the atmosphere the suit protects a player from.
    * @return the atmosphere of the suit
    */
  Atmosphere getAtmosphere();

  /**
    * Set the atmosphere the suit will protect a player from.
    * @param a the new value of the atmosphere.
    */
  void setAtmosphere(Atmosphere a);

 private:
  Atmosphere atmosphere;
};


#endif // SUIT_H
