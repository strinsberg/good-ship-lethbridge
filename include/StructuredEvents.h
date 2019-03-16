/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-08
 */

#ifndef STRUCTUREDEVENTS_H
#define STRUCTUREDEVENTS_H

#include "EventGroup.h"
#include "ObjectBlueprint.h"
#include "Entity.h"
#include <string>
#include <vector>


/**
  * A collection of sequenced events when execute is
  * called the next current events execute is called.
  * Can be set to repeat when the last event is reached
  * or it just repeats the final event every time it is
  * executed.
  */
class StructuredEvents : public EventGroup {
 public:
  StructuredEvents(std::istream& is = std::cin, std::ostream& os = std::cout);
  virtual ~StructuredEvents();
  std::string execute(Entity* affected);
  ObjectBlueprint* makeBlueprint() const;

  /**
    * Return the index of the current event.
    * @return currentEvent
    */
  int getCurrentIndex();

  /**
    * Returns if the events repeat when you get to the end
    * or is done.
    * @return repeats
    */
  bool getRepeats();

  /**
    * Set weather the events repeat when they finish
    * @param r if the events repeat
    */
  void setRepeats(bool r);

  /**
    * Sets the current index in the event list to i
    * @param i the new index.
    */
  void setCurrentIndex(int i) {
    currentEvent = i;  // should bounds check
  }

 private:
  int currentEvent;
  bool repeats;

  StructuredEvents(const StructuredEvents& other);
  StructuredEvents& operator=(const StructuredEvents& other);
};

#endif // STRUCTUREDEVENTS_H
