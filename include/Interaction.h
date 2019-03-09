/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-09
 */

#ifndef INTERACTION_H
#define INTERACTION_H

#include "Event.h"


class Interaction : public Event
{
  public:
    Interaction(std::istream& is = std::cin, std::ostream& os = std::cout);
    virtual ~Interaction();
    std::string execute(std::vector<Entity*>& affected);
    ObjectBlueprint* makeBlueprint() const;

    /**
      * Add a new option to the interaction. Transfers ownership of the event.
      * @param t the title the option
      * @param e the associated event
      */
    void addOption(std::string t, Event* e);

  private:

    struct Option {
      std::string title = "";  // Menu title
      Event* event = nullptr;  // Owns this event
      //~Option() {delete event;}
    };

    std::vector<Option> options;

    Interaction(const Interaction& other);
    Interaction& operator=(const Interaction& other);
};

#endif // INTERACTION_H
