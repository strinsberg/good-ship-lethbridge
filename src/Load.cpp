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

bool stob(const std::string& str) {
  return str == "true";
}

void updateEntity(Game*,ObjectBlueprint*);
void updateEvent(Game*,ObjectBlueprint*);
void updateInteraction(Game*,ObjectBlueprint*);
Event* findEvent(Game*, std::string);
void moveEntity(Game*, Entity*, std::string);

Load::Load(Game* g) :GameCommand(g) {}

Load::~Load() {}

std::string Load::execute() {
  // read in file data
  std::string filename;
  if (noun.empty())
    filename = game->getPlayer()->getSpec()->getName() + ".save";
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
  while (next != GameData::eof) {
    next = gd.nextObject();
    ObjectBlueprint* bp = new ObjectBlueprint(next);
    blueprints.push_back(bp);
  }

  Player* player(game->getPlayer());
  Room* r = player->getCurrentRoom();
  r->addEntity(player);

  for (auto bp : blueprints) {
    std::string type = bp->getType();
    std::string name = bp->getField("name");
    if (type == ObjectBlueprint::null)
      continue;

    if (type == "item" || type == "door" || type == "npc" || type == "container" || type == "room") {
      updateEntity(game, bp );
    } else if (type == "inform" || type == "keylock" || type == "event_group" || type == "interaction" ||
               type == "question_lock" || type == "move_items" || type == "check_suit" || type == "activate") {
      updateEvent(game, bp );
    } else if (type == "structured_event") {
      updateInteraction(game, bp );
    } else if (type == "player") {
      game->getPlayer()->setCurrentRoom( game->getRoom( bp->getField("room")) );
    }

    delete bp;
    bp = nullptr;
  }
  // put rooms into game->rooms map
  // put player into game
  r->removeEntity(player);

  return "Loaded game " + noun;
}


void updateInteraction(Game* g, ObjectBlueprint* bp) {
  Event* e = g->getEvent( bp->getField("name") );
  if (e != nullptr) {
    StructuredEvents* event = static_cast<StructuredEvents*>(e);
    event->getSpec()->setDone( stob(bp->getField("done") ));
    event->setCurrentIndex( std::stoi(bp->getField("index")) );
  }
}

void updateEntity(Game* g, ObjectBlueprint* bp) {
  Entity* ent = nullptr;
  for (auto rPair : g->getRooms()) {
    ent = rPair.second->search( bp->getField("name") );
    if (ent != nullptr) {
      moveEntity(g, ent, bp->getField("owner"));
      ent->getState()->setActive( stob(bp->getField("active")) );
      ent->getState()->setObtainable( stob(bp->getField("obtainable")) );
      ent->getState()->setHidden( stob(bp->getField("hidden")) );
      //std::cout << ent->getSpec()->getName() << " " << stob(bp->getField("active")) << std::endl;
      return;
    }
  }
}

void updateEvent(Game* g, ObjectBlueprint* bp) {
  Event* event = g->getEvent( bp->getField("name") );
  if (event != nullptr) {
    event->getSpec()->setDone( stob(bp->getField("done")) );
    //std::cout << event->getSpec()->getName() << " " << stob(bp->getField("done")) << std::endl;
  }
}

void moveEntity(Game* g, Entity* entity, std::string newOwner) {
  std::string itemName = entity->getSpec()->getName();

  Entity* owner = nullptr;
  for (auto rPair : g->getRooms()) {
    owner = rPair.second->findOwner(itemName);

    if (owner != nullptr && owner->getSpec()->getName() != newOwner) {
      MoveItems move(owner, itemName);
      move.setGive(true);

      Entity* giveTo = nullptr;
      for (auto rPair : g->getRooms()) {
        if (rPair.second->getSpec()->getName() == newOwner) {
          std::cout << rPair.second->getSpec()->getName() << " - " << itemName << " - " << owner->getSpec()->getName() <<std::endl;
          giveTo = rPair.second;
          move.execute(giveTo);
          return;
        } else {
          giveTo = rPair.second->search(newOwner);
          if (giveTo != nullptr) {
            move.execute(giveTo);
            return;
          }
        }
      }
    }
  }
}
