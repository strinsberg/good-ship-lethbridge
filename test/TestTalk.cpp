/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#include "Talk.h"
#include "Npc.h"
#include "Inform.h"
#include "Entity.h"
#include <string>
#include "gtest/gtest.h"

TEST(TalkTests, constructor_get) {
    Player* p = new Player("id7193");
    Talk t(p);
    EXPECT_EQ(t.getNoun(), "");
    EXPECT_EQ(t.getPlayer(), p);
    delete p;
}

TEST(TalkTests, set_noun) {
    Player* p = new Player("id7193");
    Talk t(p);
    t.setNoun("Laser");
    EXPECT_EQ(t.getNoun(), "Laser");
    delete p;
}

TEST(TalkTests, execute_npc_has_talk_event) {
    Player* p = new Player("player123");
    Npc* npc = new Npc("npc123");
    npc->getSpec()->setName("ted");
    Room* room = new Room("id7193");
    room->addEntity(npc);
    p->setCurrentRoom(room);
    Inform* tell = new Inform("inf123", "Hi, how are you?");
    npc->addEvent("talk", tell);
    Talk talk(p);
    talk.setNoun("ted");

    EXPECT_EQ("Hi, how are you?", talk.execute());
    delete p;
    delete room;
}

TEST(TalkTests, execute_npc_default_talk) {
    Player* p = new Player("player123");
    Npc* npc = new Npc("npc123");
    npc->getSpec()->setName("ted");
    Room* room = new Room("id7193");
    room->addEntity(npc);
    p->setCurrentRoom(room);
    Talk talk(p);
    talk.setNoun("ted");

    EXPECT_EQ("They don't have anything to say!", talk.execute());
    delete p;
    delete room;
}

TEST(TalkTests, execute_inactive) {
    Player* p = new Player("player123");
    Npc* npc = new Npc("npc123");
    npc->getSpec()->setName("ted");
    npc->getState()->setActive(false);
    Room* room = new Room("id7193");
    room->addEntity(npc);
    p->setCurrentRoom(room);
    Inform* tell = new Inform("inf123", "Hi, how are you?");
    npc->addEvent("talk", tell);
    Talk talk(p);
    talk.setNoun("ted");

    EXPECT_EQ("ted can't talk right now", talk.execute());
    delete p;
    delete room;
}

TEST(TalkTests, execute_item_does_not_exist) {
    Player* p = new Player("id7193");
    Room* room = new Room("id78y9");
    p->setCurrentRoom(room);
    Talk talk(p);
    talk.setNoun("ted");

    EXPECT_EQ("There is no ted!", talk.execute());
    delete p;
    delete room;
}

TEST(TalkTests, execute_has_no_talk) {
    Player* p = new Player("id7193");

    Entity* i = new Entity();
    i->getSpec()->setName("box");

    Room* room = new Room("idh983");
    room->addEntity(i);
    p->setCurrentRoom(room);

    Talk talk(p);
    talk.setNoun("box");

    EXPECT_EQ("Nothing happens", talk.execute());
    delete p;
    delete room;
}
