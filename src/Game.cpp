/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "Parser.h"
#include "Command.h"
#include "Exceptions.h"
#include "StructuredEvents.h"
#include <string>
#include <map>
#include <iostream>

using std::map;
using std::string;

Game::Game(std::istream& is, std::ostream& os) : rooms(map<string, Room*>()),
    player(nullptr), in(is), out(os), running(true) {
  // Create a player with a blank spec
  player = new Player("blankstartingplayer1230u90egidf");
  EntitySpec* spec = new EntitySpec();
  spec->setName("None");
  spec->setDescription("None");
  player->setSpec(spec);
  spec = nullptr;
}

Game::~Game() {
  delete player;
  for (auto r : rooms)
    delete r.second;
}

Player* Game::getPlayer() const {
  return player;
}

void Game::setPlayer(Player* p) {
  delete player;
  player = p;
}

Room* Game::getRoom(const std::string& id) {
  auto it = rooms.find(toLower(id));
  if (it == rooms.end())
    return nullptr;
  return it->second;
}

void Game::addRoom(const string& id, Room* room) {
  if (rooms.find(toLower(id)) != rooms.end())
    throw invalid_parameter_error("There is a room with that id already!");
  rooms[toLower(id)] = room;
}

int Game::numRooms() {
  return rooms.size();
}

bool Game::isRunning() {
  return running;
}

void Game::stop() {
  running = false;
}

void Game::run() {
  while (running) {
    std::string input;
    out << "> ";
    std::getline(in, input);

    input = toLower(input);

    if (input != "") {
      Command* c;
      Parser p(input, this);
      c = p.parse();
      std::cout << std::endl << "----------------------" << std::endl;
      out << c->execute() << std::endl;
      delete c;
    }


    if (player->getState()->getHidden()) {
      out << std::endl << "Game Over!" << std::endl;
      out << "Thanks for playing!" << std::endl;
      running = false;
    }
  }
}
Event* Game::getEvent(const std::string& name) {
  auto it = events.find(toLower(name));
  if (it == events.end())
    return nullptr;
  return it->second;
}

void Game::addEvent(const string& name, Event* event) {
  events[ toLower(name) ] = event;
}

string Game::toLower(const string& str) {
  string lower;
  for (auto c : str)
    lower.push_back(tolower(c));
  return lower;
}

std::map<std::string, Room*>& Game::getRooms() {
  return rooms;
}

void Game::updateInteraction(ObjectBlueprint* bp) {
/*  Event* e = getEvent(bp->getField("name"));
  if (e != nullptr) {
    StructuredEvents* event = static_cast<StructuredEvents*>(e);
    event->getSpec()->setDone(stob(bp->getField("done")));
    event->setCurrentIndex(std::stoi(bp->getField("index")));
  }*/
}

void Game::updateEntity(ObjectBlueprint* bp) {
/*  for (auto rPair : getRooms()) {
    Entity* ent = rPair.second->search(bp->getField("name"));
    if (ent != nullptr) {
      moveEntity(ent, bp->getField("owner"));
      ent->getState()->setActive(stob(bp->getField("active")));
      ent->getState()->setObtainable(stob(bp->getField("obtainable")));
      ent->getState()->setHidden(stob(bp->getField("hidden")));

      return;
    }
  }*/
}

void Game::updateEvent(ObjectBlueprint* bp) {
 /* Event* event = getEvent(bp->getField("name"));
  if (event != nullptr) {
    event->getSpec()->setDone(stob(bp->getField("done")));
  }*/
}

void Game::moveEntity(Entity* entity, std::string newOwner) {
  std::string itemName = entity->getSpec()->getName();
/*
  for (auto rPair : getRooms()) {
    Entity* owner = rPair.second->findOwner(itemName);

    if (owner != nullptr && owner->getSpec()->getName() != newOwner) {
      MoveEntitys moveEntity(owner, itemName);
      moveEntity.setGive(true);

      Entity* giveTo = nullptr;
      for (auto rPair : getRooms()) {
        if (rPair.second->getSpec()->getName() == newOwner) {
          std::cout << rPair.second->getSpec()->getName();
          std::cout << " - " << itemName << " - ";
          std::cout << owner->getSpec()->getName() <<std::endl;
          giveTo = rPair.second;
          moveEntity.execute(giveTo);
          return;
        } else {
          giveTo = rPair.second->search(newOwner);
          if (giveTo != nullptr) {
            moveEntity.execute(giveTo);
            return;
          }
        }
      }
    }
  }*/
}

bool Game::stob(const std::string& str) {
  return str == "true";
}
