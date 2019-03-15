/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Interaction.h"
#include "Event.h"
#include "ObjectBlueprint.h"
#include "Inform.h"
#include "Entity.h"
#include "Player.h"
#include <string>
#include <vector>
#include <sstream>
#include "gtest/gtest.h"


TEST(InteractionTests, constructor_get) {
  Interaction i;
  EXPECT_EQ(i.getMessage(), "");
  EXPECT_EQ(i.getSpec()->getName(), "");
}

TEST(InteractionTests, set_message) {
  Interaction i;
  i.setMessage("You can't use that!");
  EXPECT_EQ(i.getMessage(), "You can't use that!");
}

TEST(InteractionTests, set_spec) {
  Interaction i;
  EventSpec* spec = new EventSpec();
  i.setSpec(spec);
  EXPECT_EQ(i.getSpec(), spec);
}

TEST(InteractionTests, add_option_execute) {
  std::stringstream in, out;
  Interaction i(in, out);

  Event* e = new Inform();
  e->setMessage("You go to sleep");
  i.addOption("Sleep", e);

  in << "1\n2";
  Entity* p = new Player();
  std::string result = i.execute(p);

  EXPECT_EQ("Please choose an option number:\n1. Sleep\n2. Cancel\n>>> You go to sleepPlease choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
            out.str());
  EXPECT_EQ(result, "canceled");
  delete p;
}

TEST(InteractionTests, execute_cancel) {
  std::stringstream in, out;
  Interaction i(in, out);

  Event* e = new Inform();
  e->setMessage("You go to sleep");
  i.addOption("Sleep", e);

  in << "2";
  Entity* p = new Player();
  std::string result = i.execute(p);

  EXPECT_EQ("Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
            out.str());
  EXPECT_EQ(result, "canceled");
  delete p;
}

TEST(InteractionTests, execute_bad_choice) {
  std::stringstream in, out;
  Interaction i(in, out);

  Event* e = new Inform();
  e->setMessage("You go to sleep");
  i.addOption("Sleep", e);

  in << "20\n2";
  Entity* p = new Player();
  std::string result = i.execute(p);

  EXPECT_EQ("Please choose an option number:\n1. Sleep\n2. Cancel\n>>> Not a valid choice!Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
            out.str());
  EXPECT_EQ(result, "canceled");
  delete p;
}

TEST(InteractionTests, execute_bad_choice_not_number) {
  std::stringstream in, out;
  Interaction i(in, out);

  Event* e = new Inform();
  e->setMessage("You go to sleep");
  i.addOption("Sleep", e);

  in << "steve\n2";
  Entity* p = new Player();
  std::string result = i.execute(p);

  EXPECT_EQ("Please choose an option number:\n1. Sleep\n2. Cancel\n>>> Please enter a number!Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
            out.str());
  EXPECT_EQ(result, "canceled");
  delete p;
}

TEST(InteractionTests, make_blueprint) {
  Interaction i;
  i.setMessage("This interaction");

  EventSpec* e = new EventSpec();
  e->setName("blank");
  e->setDone(false);
  i.setSpec(e);

  Event* in = new Inform();
  in->setMessage("You go to sleep");
  i.addOption("Sleep", in);

  ObjectBlueprint* o = i.makeBlueprint();
  EXPECT_EQ(o->getType(), "interaction");
  EXPECT_EQ(o->getField("message"), "This interaction");
  EXPECT_EQ(o->getField("name"), "blank");
  EXPECT_EQ(o->getField("done"), "false");

  EXPECT_EQ("{\ntype=inform",
            o->toString().substr(72, 13));
  delete o;
}
