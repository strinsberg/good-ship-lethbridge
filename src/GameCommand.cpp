/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "GameCommand.h"
#include "Game.h"

GameCommand::GameCommand() : game(nullptr) {}

GameCommand::~GameCommand() {
  if (game != nullptr)
    delete game;
}

Game* GameCommand::getGame() {
  return game;
}

void GameCommand::setGame(Game* g) {
  game = g;
}
