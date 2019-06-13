/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-23
 */

#include "Action.h"
#include "Entity.h"
#include "Player.h"
#include "Exceptions.h"
#include <string>


Action::Action(Player* p) : player(p) {}

Action::~Action() {}

const Player* Action::getPlayer() const {
    return player;
}

Entity* Action::getEntity() {
    if (player == nullptr)
        throw unfinished_object_error("Action has no Player!");

    Entity* e = player->search(noun);
    if (e != nullptr && !e->getState()->getHidden())
        return e;

    e = player->getCurrentRoom()->search(noun);
    if (e != nullptr && !e->getState()->getHidden())
        return e;

    return nullptr;
}
