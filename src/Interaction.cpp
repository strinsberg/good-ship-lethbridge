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

Interaction::Interaction(std::istream& is, std::ostream& os)
  : Event(is, os), options(std::vector<Option>()), breakOut(false) {}

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
    out << "Please choose an option number:" << std::endl;

    size_t i;
    for (i = 0; i < options.size(); i++) {
      out << i + 1 << ". ";
      out << options[i].title << std::endl;
    }
    out << i + 1 << ". Cancel" << std::endl;
    out << ">>> ";

    std::string choice;

    getline(in, choice);
    try {
      int ch = std::stoi(choice);
      if (ch == options.size() + 1)
        return "Done";
      else if (ch <= options.size() && ch > 0)
        out << options.at(ch - 1).event->execute(affected);
      else
        out << "Not a valid choice!";
    } catch (std::invalid_argument e) {
      out << "Please enter a number!";
    }
    if (breakOut)
      return "";
    out << std::endl << std::endl;
  }
}

ObjectBlueprint* Interaction::makeBlueprint() const {
  ObjectWithContentsBlueprint* b = new ObjectWithContentsBlueprint();

  b->setField("type", "interaction");
  b->setField("message", message);
  if (spec != nullptr) {
    b->setField("name", spec->getName());
    std::string d = spec->isDone() ? "true" : "false";
    b->setField("done", d);
  }
  std::string bo = breakOut ? "true" : "false";
  b->setField("break_out", bo);

  for (auto o : options) {
    ObjectBlueprint* ebp = o.event->makeBlueprint();
    ebp->setField("owner", spec->getName());
    b->addBlueprint(ebp);
  }

  return b;
}

void Interaction::setBreakOut(bool b) {
  breakOut = b;
}

bool Interaction::getBreakOut() {
  return breakOut;
}
