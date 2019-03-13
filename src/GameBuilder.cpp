/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Item.h"
#include "Entity.h"
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
                "The best room on the ship! You are the captain after all.",
                true, false, false);
  g->addRoom("Captain's Room", captains_room);

  // Create objects ///////////////////////////////////////////////////////////
  Entity* box = new Container();
  addEntityInfo(box,
                "Box",
                "a small metallic container, maybe filled with treasure!",
                true, true, false);
  captains_room->addEntity(box);

  Container* desk = new Container();
  addEntityInfo(desk,
                "Desk",
                "futuristic looking desk!",
                true, false, false);
  captains_room->addEntity(desk);

  Entity* bed = new Item();
  addEntityInfo(bed,
                "Bed",
                "your bed",
                true, false, false);
  captains_room->addEntity(bed);

  Entity* computer = new Item();
  addEntityInfo(computer,
                "computer terminal",
                "Captain's personal computer terminal",
                true, false, false);
   desk->addEntity(computer);

  // Create events ////////////////////////////////////////////////////////////



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
