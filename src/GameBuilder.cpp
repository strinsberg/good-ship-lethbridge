/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"

GameBuilder::GameBuilder() {}

GameBuilder::~GameBuilder() {}

Game* GameBuilder::newGame(std::string name) {
  // Create a game
  Game* g = new Game();

  // Create Rooms /////////////////////////////////////////////////////////////
  Room* r = makeRoom("Captain's Room",
                     "The best room on the ship! Your the captain after all.");
  g->addRoom("Captain's Room", r);


  // Create player ////////////////////////////////////////////////////////////
  Player* p = new Player();
  p->setSpec( makeEntitySpec(name, "It's you!"));
  g->setPlayer(p);

  // Return the game
  return g;
}

Room* GameBuilder::makeRoom(std::string name, std::string description) {
  Room* room = new Room();

  room->setSpec( makeEntitySpec(name, description) );

  EntityState* state = new EntityState();
  state->setObtainable(false);  // You can't take a room
  room->setState(state);

  return room;
}

EntitySpec* GameBuilder::makeEntitySpec(std::string name, std::string description) {
  EntitySpec* spec = new EntitySpec();
  spec->setName(name);
  spec->setDescription(description);
  return spec;
}
