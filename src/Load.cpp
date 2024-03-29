/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Load.h"
#include "Game.h"
#include "GameData.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include "Event.h"
#include "Action.h"
#include "StructuredEvents.h"
#include "MoveItems.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

std::string hash_name(const std::string&);

Load::Load(Game* g) : GameCommand(g) {}

Load::~Load() {}

std::string Load::execute() {
  // read in file data
  std::string filename;
  if (noun.empty())
    filename = "."
               + hash_name(game->getPlayer()->getSpec()->getName())
               + ".save";
  else
    filename = noun + ".save";

  std::string line;
  std::stringstream data;
  std::ifstream fs;
  fs.open(filename);  // should handle errors
  if (!fs.is_open())
    return "Unable to load data! Could not open file " + filename;

  while (getline (fs, line))
    data << line;
  fs.close();

  // make blueprints for it all
  std::vector<ObjectBlueprint*> blueprints;
  GameData gd(data.str());
  std::string next = gd.nextObject();
  while (next != GameData::eof()) {
    next = gd.nextObject();
    ObjectBlueprint* bp = new ObjectBlueprint(next);
    blueprints.push_back(bp);
  }

  Player* player(game->getPlayer());
  Room* r = player->getCurrentRoom();
  r->addEntity(player);

  for (auto bp : blueprints) {
    std::string type = bp->getType();
    if (type == ObjectBlueprint::null())
      continue;

    if (type == "item" || type == "door"
        || type == "npc" || type == "container"
        || type == "room") {
      game->updateEntity(bp);
    } else if (type == "inform" || type == "keylock"
               || type == "event_group"
               || type == "interaction"
               || type == "question_lock" || type == "move_items"
               || type == "check_suit"
               || type == "activate") {
      game->updateEvent(bp);
    } else if (type == "structured_event") {
      game->updateInteraction(bp);
    } else if (type == "player") {
      game->getPlayer()->setCurrentRoom(game->getRoom(bp->getField("room")));
    }

    delete bp;
    bp = nullptr;
  }
  // put rooms into game->rooms map
  // put player into game
  r->removeEntity(player);

  return "Loaded game " + noun;
}
