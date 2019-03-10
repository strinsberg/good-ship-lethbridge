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
#include <string>
#include <vector>
#include <sstream>
#include "gtest/gtest.h"


TEST(InteractionTests, constructor_get) {
  Interaction i;
  EXPECT_EQ(i.getMessage(), "");
  EXPECT_EQ(i.getSpec(), nullptr);
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

  in << 1;
  Entity* p;
  std::string result = i.execute(p);

  EXPECT_EQ(out.str(), "Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ");
  EXPECT_EQ(result, "You go to sleep");
}

TEST(InteractionTests, execute_cancel) {
  std::stringstream in, out;
  Interaction i(in, out);

  Event* e = new Inform();
  e->setMessage("You go to sleep");
  i.addOption("Sleep", e);

  in << 2;
  Entity* p;
  std::string result = i.execute(p);

  EXPECT_EQ(out.str(), "Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ");
  EXPECT_EQ(result, "canceled");
}

TEST(InteractionTests, execute_bad_choice) {
  std::stringstream in, out;
  Interaction i(in, out);

  Event* e = new Inform();
  e->setMessage("You go to sleep");
  i.addOption("Sleep", e);

  in << 20;
  Entity* p;
  std::string result = i.execute(p);

  EXPECT_EQ(out.str(), "Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ");
  EXPECT_EQ(result, "Not a valid choice!");
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

  EXPECT_EQ(o->toString(),  // This is not a good test
            "{\ntype=interaction,\ndone=false,\n"
            "message=This interaction,\nname=blank,\n}\n"
            "{\ntype=inform,\nmessage=You go to sleep,\n}");

}
