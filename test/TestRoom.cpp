/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Room.h"
#include "Entity.h"
#include "Inform.h"
#include "Atmosphere.h"
#include "Protected.h"
#include "ConditionalEvent.h"
#include "Kill.h"
#include "Player.h"
#include <string>
#include "gtest/gtest.h"

TEST(RoomTests, constructor_get) {
  Room r("id7193");
  EXPECT_EQ("", r.getSpec()->getName());
  EXPECT_EQ(true, r.getState()->getObtainable());
}

TEST(RoomTests, enter_no_event) {
  Room r("room123");
  r.getSpec()->setName("Common room");
  r.getSpec()->setDescription("A good place for the crew to relax");

  EXPECT_EQ("Common room\nA good place for the crew to relax", r.enter(nullptr));
}

TEST(RoomTests, enter_custom_event) {
  Room r("room123");
  r.getSpec()->setName("Common room");
  r.getSpec()->setDescription("A good place for the crew to relax");

  Protected* pro = new Protected(Atmosphere::RADIATION);
  ConditionalEvent* cond = new ConditionalEvent("cond123");
  cond->setCondition(pro);
  cond->setSuccess(new Inform("inf123","Good thing your protected from the radiation"));
  cond->setFailure(new Kill("kill123", "You are not protected from the radiation!"));

  r.addEvent("enter", cond);

  Player* p = new Player("p123");
  p->getSpec()->setName("Steve");
  EXPECT_EQ("You are not protected from the radiation!\nSteve is Dead!", r.enter(p));
  delete p;
}

TEST(RoomTests, describe) {
  Room r("id7193");
  r.getSpec()->setName("Captain's Room");
  r.getSpec()->setDescription("It's your room!");

  Entity* e = new Entity("id123");
  e->getSpec()->setDescription("something fun");
  e->getSpec()->setName("party");
  r.addEntity(e);

  EXPECT_EQ("Location: Captain's Room\n"
            "It's your room!\nparty -> something fun", r.describe());
}

TEST(RoomTests, set_get_atmosphere) {
  Room r("id7193");
  r.setAtmosphere(Atmosphere::SPACE);
  EXPECT_EQ(Atmosphere::SPACE, r.getAtmosphere());
}
