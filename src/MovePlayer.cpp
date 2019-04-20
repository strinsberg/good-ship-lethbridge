#include "MovePlayer.h"
#include "Player.h"
#include "Door.h"

MovePlayer::MovePlayer(std::string id, Door* owner)
    : Event(id), door(owner) {}

MovePlayer::~MovePlayer() {}

std::string MovePlayer::execute(Entity* player) {
  if (Player* p = dynamic_cast<Player*>(player)) {
    if (door->getState()->getActive()) {
      p->setCurrentRoom(door->getDestination());
      return "You use the " + door->getSpec()->getName();
    } else {
      return "For some reason you can't";
    }
  }
  return "That can't use doors";
}
