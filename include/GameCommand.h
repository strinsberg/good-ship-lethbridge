#ifndef CALRISSIEN_2720_GAME_COMMAND_H
#define CALRISSIEN_2720_GAME_COMMAND_H

#include "Command.h"
#inlcude "Game.h"
#include <string>


/**
  * Interface / Base class for all game related commands.
  * eg) save, load, quit, etc.
  */
class GameCommand : public Command
{
  public:
    GameCommand();
    virtual ~GameCommand();
    virtual std::string execute();

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
