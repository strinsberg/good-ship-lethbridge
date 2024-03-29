/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "Activate.h"
#include "Event.h"
#include "Item.h"
#include "EntityState.h"
#include <string>
#include "gtest/gtest.h"

TEST(ActivateTests, constructor_get) {
  Entity* i = new Item();
  Activate a(i);
  EXPECT_EQ("", a.getMessage());
  EXPECT_EQ(i, a.getTarget());
  EXPECT_EQ("", a.getSpec()->getName());
  delete i;
}

TEST(ActivateTests, set_target) {
  Entity* i = new Item();
  Activate a(i);
  Item* t = new Item();
  EXPECT_EQ(i, a.getTarget());
  a.setTarget(t);
  EXPECT_EQ(t, a.getTarget());
  delete i;
  delete t;
}

TEST(ActivateTests, execute) {
  Entity* i = new Item();
  i->getSpec()->setName("Lamp");
  i->getState()->setActive(false);

  Entity* e = new Item();

  Activate a(i);
  a.setMessage("You turn on the lamp");
  EXPECT_EQ(false, i->getState()->getActive());
  EXPECT_EQ("You turn on the lamp", a.execute(e));
  EXPECT_EQ(true, i->getState()->getActive());
  delete e;
  delete i;
}

TEST(ActivateTests, execute_already_on) {
  Entity* i = new Item();
  i->getSpec()->setName("Lamp");

  Entity* e = new Item();

  Activate a(i);
  a.setMessage("You turn on the lamp");
  EXPECT_EQ("Already done", a.execute(e));
  EXPECT_EQ(true, i->getState()->getActive());
  delete e;
  delete i;
}

TEST(ActivateTests, make_blueprint) {
  Item* target = new Item();
  Activate a(target);

  ObjectBlueprint* ob = a.makeBlueprint();
  EXPECT_EQ("{\ntype=activate,\ndone=false,\nmessage=,\nname=,\ntarget=,\n}"
            , ob->toString());

  delete target;
  delete ob;
}
