/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-20
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
  Container* findHere(std::map<std::string, Room*>& rooms, std::string ownerId);
  Atmosphere sToAtmos(std::string str);

  void makeRooms(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);
  void makeDoors(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);
  void makeContainers(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);
  void makeNpcs(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);
  void makeEntities(std::vector<ObjectBlueprint*>& blueprints, std::map<std::string, Room*>& rooms);

  GameBuilder(const GameBuilder& other);
  GameBuilder& operator=(const GameBuilder& other);
};

#endif // GAMEBUILDER_H
