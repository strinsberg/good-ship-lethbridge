/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef INTERACTION_H
#define INTERACTION_H

#include "Event.h"
#include "Interactable.h"
#include "Entity.h"
#include <string>
#include <vector>

/**
  * An event to interact with the player. Lists some choices
  * and allows their selection to run associated events.
  */
class Interaction : public Event, public Interactable {
  public:
    /**
      * Create an Interaction object with in and out streams
      * @param in an istream (default cin)
      * @param out an ostream (default cout)
      */
    Interaction(std::string id);

    virtual ~Interaction();
    std::string execute(Entity* affected);

    /**
      * Add a new option to the interaction. Transfers ownership of the event.
      * @param t the title the option
      * @param e the associated event
      */
    void addOption(std::string t, Event* e);

    /**
      * Returns if the interaction will end once you have made a choice.
      * @return breakout
      */
    bool getBreakout();

    /**
      * Sets if the interaction will end once you have made a choice.
      * @param b the new value for breakout
      */
    void setBreakout(bool b);

  private:
    /**
      * A struct to hold a title and an associated event.
      */
    struct Option {
        std::string title = "";  // Menu title
        Event* event = nullptr;  // Owns this event
    };

    std::vector<Option> options;  // stores all the options in order
    bool breakOut;

    Interaction(const Interaction& other);
    Interaction& operator=(const Interaction& other);
};

#endif // INTERACTION_H
