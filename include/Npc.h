/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#ifndef NPC_H
#define NPC_H

#include "Container.h"
#include "EntityVisitor.h"
#include <string>

/**
  * A non player character in the game.
  */
class Npc : public Container {
  public:
    Npc(std::string id);
    ~Npc();

    virtual void accept(EntityVisitor& v);
};
#endif //NPC_H
