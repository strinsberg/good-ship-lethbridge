/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-13
 */

#include "Kill.h"
#include "Event.h"
#include "Entity.h"
#include "Container.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"


TEST(KillTests, kill_entity) {
    Kill k("id123", "Why would you do that!");
    Entity* toKill = new Entity();
    toKill->getSpec()->setName("Ted");

    EXPECT_EQ("Why would you do that!\nTed is Dead!", k.execute(toKill));
    EXPECT_EQ(true, toKill->getState()->getHidden());
    delete toKill;
}
