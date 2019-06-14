/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-18
 */

#include "Kill.h"
#include "Entity.h"
#include <sstream>
#include <iostream>
#include <string>

Kill::Kill(std::string id, std::string message, bool isEnd) : Inform(id, message), ending(isEnd) {}

Kill::~Kill() {}

std::string Kill::execute(Entity* affected) {
    std::stringstream ss;
    affected->getState()->setHidden(true);
    ss << message;
    if (!ending)
        ss << std::endl << affected->getSpec()->getName() << " is Dead!";
    return ss.str();
}

void Kill::accept(EventVisitor& v) {
    v.visit(this);
}
