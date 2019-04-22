/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "Game.h"
#include <string>

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
  std::string getFileData(std::string filename);
  void makeBlueprints(std::string data, std::vector<ObjectBlueprint*>& blueprints);
  bool stob(const std::string& str);
  void setUpEntity(Entity* entity, ObjectBlueprint* bp);

  void makeRooms(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);
  void makeDoors(std::map<std::string, Room*>& rooms, std::vector<ObjectBlueprint*>& blueprints);

  GameBuilder(const GameBuilder& other);
  GameBuilder& operator=(const GameBuilder& other);
};

#endif // GAMEBUILDER_H
