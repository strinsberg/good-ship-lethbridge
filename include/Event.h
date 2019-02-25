/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_EVENT_H
#define CALRISSIEN_2720_EVENT_H

#include "ObjectBlueprint.h"
#include "EventSpec.h"
#include <string>


/**
  * An interface for game events
  */
class Event {
 public:
  Event();
  virtual ~Event();

  /**
    * Resolve the event.
    * @return a description of the results.
    */
  virtual std::string execute() = 0;

  /**
    * Create a blueprint of the event that can be used to serialize it.
    * Transfers ownership of the blueprint to the caller.
    * @return the blueprint.
    */
  virtual ObjectBlueprint* makeBlueprint() const = 0;

  /**
    * Set the message to be displayed when the event is executed
    * @param m the message
    */
  void setMessage(std::string m);

  /**
   * Transfers ownership of spec to the event
   * @param s the new spec
   */
  void setSpec(Event* s);

 protected:
  std::string message;
  EventSpec* spec;  // owns this object

 private:
  Event(const Event&);
  Event& operator=(const Event&);
};

#endif // EVENT_H
