/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#ifndef NPC_H
#define NPC_H

#include "Container.h"
#include <string>

class Npc : public Container {
 public:
  Npc();
  ~Npc();
  std::string describe() const;
  std::string use(Entity* user);
  ObjectBlueprint* makeBlueprint()const;
};
#endif //NPC_H
