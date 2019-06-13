/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#ifndef NPC_H
#define NPC_H

#include "Container.h"
#include <string>

/**
  * A non player character in the game.
  */
class Npc : public Container {
  public:
    Npc(std::string id);
    ~Npc();
};
#endif //NPC_H
