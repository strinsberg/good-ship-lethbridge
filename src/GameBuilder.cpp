/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11, 2019-04-20
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Room.h"
#include "Door.h"
#include "Npc.h"
#include "ObjectBlueprint.h"
#include "GameData.h"
#include "Exceptions.h"
#include "EventFactory.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

GameBuilder::GameBuilder() {}

GameBuilder::~GameBuilder() {}

Game* GameBuilder::newGame(std::string name) {
  // Create a game
  Game* g = new Game();
  std::vector<ObjectBlueprint*> blueprints;

  // Make a factory that has all these functions that take data and rooms
  // and create the blueprints and populate the rooms accordingly

  // make rooms
  std::map<std::string, Room*>& rooms = g->getRooms();
  std::string roomData = getFileData("gameData/rooms.data");
  makeBlueprints(roomData, blueprints);
  makeRooms(blueprints, rooms);

  // make doors
  std::string doorData = getFileData("gameData/doors.data");
  makeBlueprints(doorData, blueprints);
  makeDoors(blueprints, rooms);

  // make player here when ready

  // make npcs
  std::string npcData = getFileData("gameData/npcs.data");
  makeBlueprints(npcData, blueprints);
  makeNpcs(blueprints, rooms);

  // make containers
  std::string containerData = getFileData("gameData/containers.data");
  makeBlueprints(containerData, blueprints);
  makeContainers(blueprints, rooms);

  // make entities
  std::string entityData = getFileData("gameData/entities.data");
  makeBlueprints(entityData, blueprints);
  makeEntities(blueprints, rooms);

  // make events
  std::string eventData = getFileData("gameData/events.data");
  makeBlueprints(eventData, blueprints);
  EventFactory ef(blueprints, rooms);
  ef.makeEvents();

  // Create player
  // Eventually make this something that comes from a text file as well
  // because if you ever let people make their own world they will want to
  // specify where the player starts and items etc.
  Player* p = new Player();
  p->setCurrentRoom(rooms.find("rmcapt")->second);
  p->getSpec()->setName(name);
  g->setPlayer(p);

  // Delete the blueprints
  for (auto bp : blueprints) {
    delete bp;
  }

  // Return the game
  return g;
}

// Private ///////////////////////////////////////////////////////////////////

std::string GameBuilder::getFileData(std::string filename) {
  std::string line;
  std::stringstream data;
  std::ifstream fs;

  fs.open(filename);  // need to handle errors
  if (!fs.is_open()) {
    throw my_file_error("Error: Unable to read game data! File: " + filename);
  }

  while (getline (fs, line))
    data << line;
  fs.close();

  return data.str();
}

void GameBuilder::makeBlueprints(std::string data, std::vector<ObjectBlueprint*>& blueprints) {
  GameData gd(data);
  blueprints.clear();

  std::string next = gd.nextObject();
  while (next != GameData::eof()) {
    ObjectBlueprint* bp = new ObjectBlueprint(next);
    blueprints.push_back(bp);
    next = gd.nextObject();
  }
}

bool GameBuilder::stob(std::string str) {
  return str == "true";
}

void GameBuilder::setUpEntity(Entity* entity, ObjectBlueprint* bp) {

  EntitySpec* spec = entity->getSpec();
  std::string id = bp->getField("id");
  std::string name = bp->getField("name");
  std::string desc = bp->getField("description");
  if (id == ObjectBlueprint::null()
      || name == ObjectBlueprint::null()
      || desc == ObjectBlueprint::null()) {
    throw unfinished_object_error("Error: Object data is missing! ID: " + id + ", Name: " + name + ", Description: " + desc);
  }
  spec->setId(id);
  spec->setName(name);
  spec->setDescription(desc);

  EntityState* state = entity->getState();
  std::string act = bp->getField("active");
  std::string obt = bp->getField("obtainable");
  std::string hid = bp->getField("hidden");

  if (act != ObjectBlueprint::null())
    state->setActive(stob(act));
  if (obt != ObjectBlueprint::null())
    state->setObtainable(stob(obt));
  if (hid != ObjectBlueprint::null())
    state->setHidden(stob(hid));
}

Container* GameBuilder::findHere(std::map<std::string, Room*>& rooms, std::string ownerId) {
  for (auto it : rooms) {
    // If the owner is a room
    if (it.second->getSpec()->getId() == ownerId)
      return it.second;

    // If the owner is some other container
    Entity* ent = it.second->searchById(ownerId);
    if (ent != nullptr) {
      Container* con = dynamic_cast<Container*>(ent);
      return con;
    }
  }
  return nullptr;
}

Atmosphere GameBuilder::sToAtmos(std::string str) {
  if (str == "radiation")
    return Atmosphere::RADIATION;
  else if (str == "space")
    return Atmosphere::SPACE;
  else
    return Atmosphere::OXYGEN;
}

// Factory methods ///////////////////////////////////////////////////////////

void GameBuilder::makeRooms(std::vector<ObjectBlueprint*>& blueprints,
                            std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    // Should check to make sure we don't have duplicate id's
    Room* room = new Room(bp->getField("id"));
    setUpEntity(room, bp);
    room->getState()->setObtainable(false);
    rooms[bp->getField("id")] = room;
  }
}

void GameBuilder::makeDoors(std::vector<ObjectBlueprint*>& blueprints,
                            std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    Room* here = rooms.find(bp->getField("here"))->second;
    Room* there = rooms.find(bp->getField("there"))->second;
    // Need error checking for these things
    Door* door = new Door(bp->getField("id"), here, there);
    setUpEntity(door, bp);
    door->getState()->setObtainable(false);
    here->addEntity(door);
  }
}

void GameBuilder::makeContainers(std::vector<ObjectBlueprint*>& blueprints,
                                 std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    // does not adequately address what happens when an entity is
    // in a container and not just a room
    Container* here = findHere(rooms, bp->getField("here"));
    Container* container = new Container(bp->getField("id"));
    setUpEntity(container, bp);
    here->addEntity(container);
  }
}

void GameBuilder::makeNpcs(std::vector<ObjectBlueprint*>& blueprints,
                                 std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    Container* here = findHere(rooms, bp->getField("here"));
    Npc* npc = new Npc(bp->getField("id"));
    setUpEntity(npc, bp);
    npc->getState()->setObtainable(false);
    here->addEntity(npc);
  }
}

void GameBuilder::makeEntities(std::vector<ObjectBlueprint*>& blueprints,
                                 std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    Container* here = findHere(rooms, bp->getField("here"));
    Entity* ent;

    std::string type = bp->getType();
    if (type == "suit")
      // only do it if the suit has no atmoshpere
      ent = new Suit(sToAtmos(bp->getField("atmosphere")));
    else
      ent = new Entity(bp->getField("id"));

    setUpEntity(ent, bp);
    here->addEntity(ent);
  }
}
