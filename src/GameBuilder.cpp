/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Room.h"
#include "Door.h"
#include "Npc.h"
#include "ObjectBlueprint.h"
#include "GameData.h"
#include "Exceptions.h"
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
  makeNpcs(blueprints, rooms);

  // make events

  // Create player
  // Eventually make this something that comes from a text file as well
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

bool GameBuilder::stob(const std::string& str) {
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
    Room* here = rooms.find(bp->getField("here"))->second;
    Container* container = new Container(bp->getField("id"));
    setUpEntity(container, bp);
    here->addEntity(container);
  }
}

void GameBuilder::makeNpcs(std::vector<ObjectBlueprint*>& blueprints,
                                 std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    Room* here = rooms.find(bp->getField("here"))->second;
    Npc* npc = new Npc(bp->getField("id"));
    setUpEntity(npc, bp);
    npc->getState()->setObtainable(false);
    here->addEntity(npc);
  }
}

void GameBuilder::makeEntities(std::vector<ObjectBlueprint*>& blueprints,
                                 std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    Room* here = rooms.find(bp->getField("here"))->second;
    Entity* ent;

    if (false) // add in other types like suit
      ent = nullptr;
    else
      ent = new Entity(bp->getField("id"));

    setUpEntity(ent, bp);
    here->addEntity(ent);
  }
}
