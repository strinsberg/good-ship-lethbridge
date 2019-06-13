/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Look.h"
#include <string>
#include "gtest/gtest.h"

TEST(LookTests, constructor_get) {
    Player* p = new Player("id7193");
    Look l(p);
    EXPECT_EQ(l.getNoun(), "");
    EXPECT_EQ(l.getPlayer(), p);
    delete p;
}

TEST(LookTests, set_noun) {
    Player* p = new Player("id7193");
    Look l(p);
    l.setNoun("Laser");
    EXPECT_EQ(l.getNoun(), "Laser");
    delete p;
}

TEST(LookTests, execute_player_has_item) {
    Player* p = new Player("id7193");
    Look l(p);

    Room r("id7h9h9");
    Container* c = new Container("idhu9h");
    c->getSpec()->setName("box");
    c->getSpec()->setDescription("a box");
    p->addEntity(c);
    p->setCurrentRoom(&r);

    l.setNoun("box");
    EXPECT_EQ(l.execute(), "You see a box");
    delete p;
}

TEST(LookTests, execute_room_has_item) {
    Player* p = new Player("id7193");
    Look l(p);

    Room r("id4d54e");
    Container* c = new Container("id5f657");
    c->getSpec()->setName("box");
    c->getSpec()->setDescription("a box");
    r.addEntity(c);
    p->setCurrentRoom(&r);

    l.setNoun("box");
    EXPECT_EQ(l.execute(), "You see a box");
    delete p;
}

TEST(LookTests, execute_no_item) {
    Player* p = new Player("id7193");
    Look l(p);

    Room r("idh870");
    p->setCurrentRoom(&r);

    l.setNoun("box");
    EXPECT_EQ(l.execute(), "There is no box");
    delete p;
}

TEST(LookTests, execute_just_look) {
    Player* p = new Player("id7193");
    Look l(p);

    Room r("idg68");
    Container* c = new Container("idd57");
    c->getSpec()->setName("box");
    c->getSpec()->setDescription("a box");
    r.addEntity(c);
    r.getSpec()->setName("This room");
    r.getSpec()->setDescription("A regular room like you've seen before");
    p->setCurrentRoom(&r);

    l.setNoun("");
    EXPECT_EQ("Location: This room\nA regular room like you've seen before\nbox -> a box",
              l.execute());
    delete p;
}
