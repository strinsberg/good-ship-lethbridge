/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_GAME_COMMAND_H
#define CALRISSIEN_2720_GAME_COMMAND_H

#include "Command.h"
#include "Game.h"
#include <string>


/**
  * Interface / Base class for all game related commands.
  * eg) save, load, quit, etc.
  */
class GameCommand : public Command {
 public:
  /**
    * Creates a Game command with a given game.
    * @param g the game the command is for.
    */
  GameCommand(Game* g);
  virtual ~GameCommand();
  virtual std::string execute() = 0;

  /**
    * Get the game. Does not transfer ownership of the game.
    * @return game.
    */
  Game* getGame();

  /**
    * Set the game. Transfers ownership to the GameCommand.
    * @param g the game.
    */
  void setGame(Game* g);

 protected:
  Game* game;  // owns this

 private:
  GameCommand(const GameCommand& other);
  GameCommand& operator=(const GameCommand& other);
};

#endif // GAMECOMMAND_H
