/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#include "Interaction.h"
#include "ObjectWithContentsBlueprint.h"
#include <iostream>
#include <exception>

Interaction::Interaction(std::istream& is, std::ostream& os)
    : Event(is, os), options(std::vector<Option>()) {}

Interaction::~Interaction() {}

void Interaction::addOption(std::string t, Event* e) {
  Option o;
  o.title = t;
  o.event = e;
  options.push_back(o);
}

std::string Interaction::execute(Entity* affected) {
  out << "Please choose an option number:" << std::endl;

  size_t i;
  for (i = 0; i < options.size(); i++) {
   out << i + 1 << ". ";
   out << options[i].title << std::endl;
  }
  out << i + 1 << ". Cancel" << std::endl;
  out << ">>> ";

  size_t choice;

  in >> choice;  // What happens if this tries to get a string?
  if (choice == options.size() + 1)
    return "canceled";
  else if (choice <= options.size() && choice > 0)
    return options.at(choice - 1).event->execute(affected);
  else
    return "Not a valid choice!";
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

  for (auto o : options) {
    b->addBlueprint(o.event->makeBlueprint());
  }

  return b;
}



