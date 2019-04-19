/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Interaction.h"
#include "ObjectWithContentsBlueprint.h"
#include "Entity.h"
#include <iostream>
#include <exception>
#include <string>
#include <vector>

Interaction::Interaction(std::string id)
  : Event(id), options(std::vector<Option>()), breakOut(false) {}

Interaction::~Interaction() {
  for (auto o : options)
    delete o.event;
}

void Interaction::addOption(std::string t, Event* e) {
  Option o;
  o.title = t;
  o.event = e;
  options.push_back(o);
}

std::string Interaction::execute(Entity* affected) {
  while (true) {
    *out << "Please choose an option number:" << std::endl;

    size_t i;
    for (i = 0; i < options.size(); i++) {
      *out << i + 1 << ". ";
      *out << options[i].title << std::endl;
    }
    *out << i + 1 << ". Cancel" << std::endl;
    *out << ">>> ";

    std::string choice;

    getline(*in, choice);
    try {
      int ch = std::stoi(choice);
      if (ch == options.size() + 1)
        return "Done";
      else if (ch <= options.size() && ch > 0)
        *out << options.at(ch - 1).event->execute(affected);
      else
        *out << "Not a valid choice!";
    } catch (const std::invalid_argument& e) {
      *out << "Please enter a number!";
    }
    if (breakOut)
      return "";
    *out << std::endl << std::endl;
  }
}

void Interaction::setBreakout(bool b) {
  breakOut = b;
}

bool Interaction::getBreakout() {
  return breakOut;
}
