/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include <string>
#include <iostream>

int main() {
  std::cout << "Welcome to Disaster On The Good Ship Lethbridge!!!!";
  std::cout << std::endl << std::endl;

  std::string name;
  while (true) {
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    if (name.length() > 100) {
      std::cout << std::endl;
      std::cout << "Invalid name: Names must be 100 characters or less!!!";
      std::cout << std::endl;
    } else {
      break;
    }
  }

  std::cout << std::endl;
  std::cout << "Welcome Captain " << name << std::endl << std::endl;

  std::cout << "You are awakened from sleep by a small explosion and"
      " alarms going off! You leap out of bed, put on your uniform and...";
  std::cout << std::endl << std::endl;

  GameBuilder builder;
  Game* g = builder.newGame(name);
  g->run();

  delete g;

  return 0;
}
