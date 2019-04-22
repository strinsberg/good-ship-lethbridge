/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Room.h"
#include "Door.h"
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

  // make rooms
  std::map<std::string, Room*>& rooms = g->getRooms();
  std::string roomData = getFileData("gameData/rooms.data");
  makeBlueprints(roomData, blueprints);
  makeRooms(blueprints, rooms);

  // make doors
  std::string doorData = getFileData("gameData/doors.data");
  makeBlueprints(doorData, blueprints);
  makeDoors(rooms, blueprints);

  // Connect all the objects together

  Player* p = new Player();
  p->setCurrentRoom(rooms.find("r1")->second);
  p->getSpec()->setName(name);
  g->setPlayer(p);

  // Return the game
  return g;
}

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

void GameBuilder::makeRooms(std::vector<ObjectBlueprint*>& blueprints,
                            std::map<std::string, Room*>& rooms) {
  for (auto bp : blueprints) {
    // Should check to make sure we don't have duplicate id's
    Room* room = new Room(bp->getField("id"));
    setUpEntity(room, bp);
    rooms[bp->getField("id")] = room;
  }
}

void GameBuilder::makeDoors(std::map<std::string, Room*>& rooms, std::vector<ObjectBlueprint*>& blueprints) {
  for (auto bp : blueprints) {
    Room* here = rooms.find(bp->getField("here"))->second;
    Room* there = rooms.find(bp->getField("there"))->second;
    // Need error checking for these things
    Door* door = new Door(bp->getField("id"), here, there);
    setUpEntity(door, bp);
    here->addEntity(door);
  }
}
