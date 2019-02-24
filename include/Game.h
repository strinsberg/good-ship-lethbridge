/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_GAME_H
#define CALRISSIEN_2720_GAME_H

#include "Room.h"
#include "Player.h"
#include <string>
#include <map>
#include <iostream>


/**
  * Object responsible for running the game
  */
class Game {
 public:
  Game(std::istream& is = std::cin, std::ostream& os = std::cout);
  virtual ~Game();

  /**
    * Run the main game loop
    */
  void run();

  /**
    * Does not Transfer ownership
    * @return the player
    */
  Player* getPlayer() const;

  /**
    * Set the player for the game. Transfers ownership to this game.
    * @param p the new player character
    */
  void setPlayer(Player* p);

  /**
    * Get a pointer to a room with a given name. Does not transfer ownership.
    * @param name the name of the room
    * @return the room with given name or nullptr
    */
  Room* getRoom(std::string name) const;

  /**
    * Add a room to the game. Transfers ownership to this game.
    * @param name the name of the room. (probably change later when room is implemented)
    * @param room the room to add
    * @throws invalid_parameter_error if a room with same name is
    * already stored
    */
  void addRoom(const std::string& name, Room* room);

  /**
    * @return the number of rooms
    */
  int numRooms();

 private:
  std::map<std::string, Room*> rooms;  // owns rooms
  Player* player;  // owns player
  std::istream& in;
  std::ostream& out;

  Game(const Game&);
  Game& operator=(const Game&);
};

#endif // GAME_H
