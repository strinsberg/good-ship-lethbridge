/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
 */

#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "Game.h"
#include "Entity.h"
#include "Event.h"
#include "Conditional.h"
#include "EventGroup.h"
#include "json.h"
#include <string>

using json = nlohmann::json;

/**
  * Builds a new game in its initial state.
  */
class GameBuilder {
 public:
  GameBuilder();
  virtual ~GameBuilder();

  /**
    * Create a new game and return it. Transfers ownership to the caller.
    */
  Game* newGame(std::string name);

 private:
  bool isEntity(std::string type);
  bool isEvent(std::string type);
  bool isCondition(std::string type);

    Entity* makeEntity(json obj);
    Event* makeEvent(json obj);
    Conditional* makeCondition(json obj);

  GameBuilder(const GameBuilder& other);
  GameBuilder& operator=(const GameBuilder& other);
};

#endif // GAMEBUILDER_H
