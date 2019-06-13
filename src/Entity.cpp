/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-18
 */

#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"
#include <string>


Entity::Entity():spec(nullptr), state(nullptr) {
    spec = new EntitySpec("", "", "");
    state = new EntityState();
}

Entity::Entity(std::string id) : Entity() {
    spec->setId(id);
}

Entity::~Entity() {
    delete spec;
    delete state;
    for (auto it : events) {
        delete it.second;
    }
}

std::string Entity::describe() const {
    return spec->getName() + " -> " + spec->getDescription();
}

EntitySpec* Entity::getSpec() const {
    return spec;
}

void Entity::setSpec(EntitySpec* s) {
    delete spec;
    spec = s;
}

EntityState* Entity::getState() const {
    return state;
}

void Entity::setState(EntityState* s) {
    delete state;
    state = s;
}

void Entity::addEvent(std::string verb, Event* event) {
    auto it = events.find(verb);
    if (it != events.end())
        delete it->second;
    events[verb] = event;
}

std::string Entity::runEvent(std::string verb, Entity* affected) {
    auto it = events.find(verb);
    if (it == events.end())
        return "Nothing happens";
    return it->second->execute(affected);
}

bool Entity::hasEvent(std::string verb) {
    auto it = events.find(verb);
    if (it == events.end())
        return false;
    else
        return true;
}

bool Entity::matches(std::string noun) {
    return spec->matches(noun);
}

void Entity::accept(Visitor& v) {
    v.visit(this);
}
