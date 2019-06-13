/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-20
 */

#include "HasItem.h"
#include "Entity.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(HasItemTests, has_item) {
    Player* p = new Player("player123");
    Entity* e = new Entity("id123");
    p->addEntity(e);

    HasItem h("id123");
    EXPECT_TRUE(h.test(p));
    delete p;
}

TEST(HasItemTests, does_not_have_item) {
    Player* p = new Player("player123");
    Entity* e = new Entity("id123");
    p->addEntity(e);

    HasItem h("id456");
    EXPECT_FALSE(h.test(p));
    delete p;
}

TEST(HasItemTests, not_a_container) {
    Entity* e = new Entity("id123");

    HasItem h("id456");
    EXPECT_FALSE(h.test(e));
}
