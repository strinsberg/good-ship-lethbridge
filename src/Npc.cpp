/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Npc.h"
#include "Container.h"
#include "Inform.h"
#include <string>

Npc::Npc(std::string id) : Container(id) {
    addEvent("talk", new Inform("hidden02925327", "They don't have anything to say!"));
}

Npc::~Npc() {}
