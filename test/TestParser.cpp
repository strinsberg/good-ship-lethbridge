/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-20
 */

#include "Parser.h"
#include "Command.h"
#include "BadInput.h"
#include "Game.h"
#include <string>
#include "gtest/gtest.h"


TEST(ParserTests, constructor) {
  Game g;
  Parser p("get laser", &g);
  EXPECT_EQ("get laser", p.getInput());
}

TEST(ParserTests, parse_bad_input) {
  Game g;
  Parser p("scubadive", &g);
  Command* c = p.parse();
  EXPECT_EQ("You can't scubadive!", c->execute());
  delete c;  // parser does not own the pointer it returns
}

TEST(ParserTests, parse_quit) {
  Game g;
  Parser p("quit", &g);
  Command* c = p.parse();
  EXPECT_EQ("Thanks for playing!", c->execute());
  EXPECT_EQ(false, g.isRunning());
  delete c;  // parser does not own the pointer it returns
}

TEST(ParserTests, parse_get) {
  Game g;
  Player* pl = new Player("id7193");
  Room* r = new Room("idf7f7");
  pl->setCurrentRoom(r);
  g.addRoom("here", r);
  g.setPlayer(pl);
  Parser p("get box", &g);
  Command* c = p.parse();
  EXPECT_EQ("There is no box", c->execute());
  delete c;
}

TEST(ParserTests, parse_drop) {
  Game g;
  Parser p("drop box", &g);
  Command* c = p.parse();
  EXPECT_EQ("You don't have that!", c->execute());
  delete c;  // parser does not own the pointer it returns
}

TEST(ParserTests, parse_look) {
  Game g;
  Player* pl = new Player("idg78");
  Room* r = new Room("idj98j9");
  pl->setCurrentRoom(r);
  g.addRoom("here", r);
  g.setPlayer(pl);
  Parser p("look box", &g);
  Command* c = p.parse();
  EXPECT_EQ("There is no box", c->execute());
  delete c;
}

TEST(ParserTests, parse_use) {
  Game g;
  Player* pl = new Player("id7193");
  Room* r = new Room("idh9h9");
  pl->setCurrentRoom(r);
  g.addRoom("here", r);
  g.setPlayer(pl);
  Parser p("use box", &g);
  Command* c = p.parse();
  EXPECT_EQ("There is no box", c->execute());
  delete c;
}

TEST(ParserTests, parse_talk) {
  Game g;
  Player* pl = new Player("id7193");
  Room* r = new Room("idg767");
  pl->setCurrentRoom(r);
  g.addRoom("here", r);
  g.setPlayer(pl);
  Parser p("talk box", &g);
  Command* c = p.parse();
  EXPECT_EQ("There is no box!", c->execute());
  delete c;
}

TEST(ParserTests, parse_help) {
  Game g;
  Parser p("help", &g);
  Command* c = p.parse();
  EXPECT_EQ("available commands are use, get, drop, inventory, "
            "look, talk, save, load, quit, and exit.", c->execute());
  delete c;  // parser does not own the pointer it returns
}
