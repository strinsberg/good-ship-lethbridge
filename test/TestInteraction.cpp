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


TEST(InteractionTests, add_option_execute) {
    std::stringstream in, out;
    Interaction i("id123");
    i.setIn(in);
    i.setOut(out);

    Event* e = new Inform("id456", "You go to sleep");
    i.addOption("Sleep", e);

    in << "1\n2";
    Entity* p = new Player("id7193");
    std::string result = i.execute(p);

    EXPECT_EQ("Please choose an option number:\n"
              "1. Sleep\n2. Cancel\n>>> "
              "You go to sleep\n\n"
              "Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
              out.str());
    EXPECT_EQ(result, "Done");
    delete p;
}

TEST(InteractionTests, execute_cancel) {
    std::stringstream in, out;
    Interaction i("id123");
    i.setIn(in);
    i.setOut(out);

    Event* e = new Inform("id456", "You can't use that!");
    i.addOption("Sleep", e);

    in << "2";
    Entity* p = new Player("id7193");
    std::string result = i.execute(p);

    EXPECT_EQ("Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
              out.str());
    EXPECT_EQ(result, "Done");
    delete p;
}

TEST(InteractionTests, execute_bad_choice) {
    std::stringstream in, out;
    Interaction i("id123");
    i.setIn(in);
    i.setOut(out);

    Event* e = new Inform("id456", "You can't use that!");
    i.addOption("Sleep", e);

    in << "20\n2";
    Entity* p = new Player("id7193");
    std::string result = i.execute(p);

    EXPECT_EQ("Please choose an option number:\n"
              "1. Sleep\n2. Cancel\n>>> Not a valid choice!\n\n"
              "Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
              out.str());
    EXPECT_EQ(result, "Done");
    delete p;
}

TEST(InteractionTests, execute_bad_choice_not_number) {
    std::stringstream in, out;
    Interaction i("id123");
    i.setIn(in);
    i.setOut(out);

    Event* e = new Inform("id456", "You can't use that!");
    i.addOption("Sleep", e);

    in << "steve\n2";
    Entity* p = new Player("id7193");
    std::string result = i.execute(p);

    EXPECT_EQ("Please choose an option number:\n"
              "1. Sleep\n2. Cancel\n>>> Please enter a number!\n\n"
              "Please choose an option number:\n1. Sleep\n2. Cancel\n>>> ",
              out.str());
    EXPECT_EQ(result, "Done");
    delete p;
}

TEST(InteractionTests, add_option_execute_breakout) {
    std::stringstream in, out;
    Interaction i("id123");
    i.setBreakout(true);
    i.setIn(in);
    i.setOut(out);

    Event* e = new Inform("id456", "You go to sleep");
    i.addOption("Sleep", e);

    in << "1\n";
    Entity* p = new Player("id7193");
    std::string result = i.execute(p);

    EXPECT_EQ(true, i.getBreakout());
    EXPECT_EQ("Please choose an option number:\n1. Sleep\n2. "
              "Cancel\n>>> You go to sleep",
              out.str());
    EXPECT_EQ("", result);
    delete p;
}
