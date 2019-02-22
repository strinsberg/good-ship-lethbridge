/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_GAME_H
#define CALRISSIEN_2720_GAME_H

#include "Room.h"
#include "Player.h"
#include <map>


/**
  * Object responsible for running the game
  */
class Game {
 public:
  Game();
  virtual ~Game();

  /**
    * Run the main game loop
    */
  void run();

  /**
    * @return the player
    */
  Player& getPlayer() const;

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
  Room* getRoom(string name) const;

  /**
    * Add a room to the game. Transfers ownership to this game.
    * @param room the room to add
    * @throws invalid_parameter_error if a room with same name is
    * already stored
    */
  void addRoom(Room* room);

 private:
  map<string, Room*> rooms;  // owns rooms
  Player* player;  // owns player

  Game(const Game&);
  Game& operator=(const Game&);
};

#endif // GAME_H
