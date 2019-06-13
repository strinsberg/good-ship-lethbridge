/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12, 2019-04-23
 */

#include "Door.h"
#include "Room.h"
#include "Player.h"
#include "Entity.h"
#include "Entity.h"
#include "TransferItem.h"
#include "Inform.h"
#include "Use.h"
#include <string>
#include "gtest/gtest.h"


TEST(DoorTests, describe) {
    Door d("id123", nullptr, nullptr);
    d.getSpec()->setDescription("a door to space");
    EXPECT_EQ("a door to space", d.describe());
}

TEST(DoorTests, get_here_destination) {
    Room* start = new Room("id456");
    Room* end = new Room("id789");

    Door d("door123", start, end);

    EXPECT_EQ(start, d.getHere());
    EXPECT_EQ(end, d.getDestination());

    delete start;
    delete end;
}

TEST(DoorTests, use_normal) {
    Player* p = new Player("id123");
    Room* start = new Room("id456");
    Room* end = new Room("id789");

    Door d("door123", start, end);
    d.getSpec()->setName("rusty door");

    p->setCurrentRoom(start);

    EXPECT_EQ("You use the rusty door", d.runEvent("use", p));
    EXPECT_EQ(end, p->getCurrentRoom());

    delete start;
    delete end;
    delete p;
}

TEST(DoorTests, use_not_active) {
    Player* p = new Player("id123");
    Room* start = new Room("id456");
    Room* end = new Room("id789");

    Door d("door123", start, end);
    d.getState()->setActive(false);

    p->setCurrentRoom(start);

    EXPECT_EQ("For some reason you can't", d.runEvent("use", p));
    EXPECT_EQ(start, p->getCurrentRoom());

    delete start;
    delete end;
    delete p;
}

TEST(DoorTests, use_entity) {
    Entity* p = new Entity("id123");
    Room* start = new Room("id456");
    Room* end = new Room("id789");

    Door d("door123", start, end);
    d.getSpec()->setName("rusty door");

    EXPECT_EQ("That can't use doors", d.runEvent("use", p));

    delete start;
    delete end;
    delete p;
}
