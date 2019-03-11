/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "Game.h"

/**
  * Builds a new game in its initial state.
  */
class GameBuilder
{
  public:
    GameBuilder();
    virtual ~GameBuilder();

    /**
      * Create a new game and return it. Transfers ownership.
      */
    Game* newGame(std::string name);

  private:
    Room* makeRoom(std::string name, std::string description);
    EntitySpec* makeEntitySpec(std::string name, std::string description);

    GameBuilder(const GameBuilder& other);
    GameBuilder& operator=(const GameBuilder& other);
};

#endif // GAMEBUILDER_H
