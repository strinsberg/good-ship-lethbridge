#include "MovePlayer.h"
#include "Player.h"

MovePlayer::MovePlayer(std::string id, Room* there)
    : Event(id), destination(there) {}

MovePlayer::~MovePlayer() {}

std::string MovePlayer::execute(Entity* player) {
  if (Player* p = dynamic_cast<Player*>(player)) {
    p->setCurrentRoom(destination);
    return "";
  }
  return "That can't use doors";
}
