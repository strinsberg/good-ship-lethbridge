/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
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
    Suit(std::string id, std::string atmos) : Entity(id) {}
    Suit(Atmosphere atmosphere=Atmosphere::OXYGEN);
    virtual ~Suit();
    std::string describe() const;

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

    Suit(const Suit& other);
    Suit& operator=(const Suit& other);
};


#endif // SUIT_H
