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

  // for AddEntityInfo(name,description,active,obtainable,hidden) //

  // Create Rooms /////////////////////////////////////////////////////////////
  Room* captains_room = new Room();
  addEntityInfo(captains_room,
                "Captain's Room",
                "The best room on the ship! Your the captain after all.",
                true, false, false);
  g->addRoom("Captain's Room", captains_room);

  // Create objects ///////////////////////////////////////////////////////////
  Entity* box = new Container();
  addEntityInfo(box,
                "Box",
                "A small metallic container, maybe filled with treasure!",
                true, true, false);
  captains_room->addEntity(box);

  // Create player ////////////////////////////////////////////////////////////
  Player* p = new Player();
  p->setSpec( makeEntitySpec(name, "It's you!"));
  p->setState( makeEntityState(true, false, false) );
  p->setCurrentRoom(captains_room);
  g->setPlayer(p);

  // Return the game
  return g;
}

EntitySpec* GameBuilder::makeEntitySpec(std::string name, std::string description) {
  EntitySpec* spec = new EntitySpec();
  spec->setName(name);
  spec->setDescription(description);
  return spec;
}

EntityState* GameBuilder::makeEntityState(bool active, bool obtainable, bool hidden) {
  EntityState* state = new EntityState();
  state->setActive(active);
  state->setObtainable(obtainable);
  state->setHidden(hidden);
  return state;
}

void GameBuilder::addEntityInfo(Entity* entity, std::string name, std::string description, bool active, bool obtainable, bool hidden) {
  entity->setSpec(makeEntitySpec(name, description));
  entity->setState(makeEntityState(active, obtainable, hidden));
}
