/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#ifndef CALRISSIEN_2720_EVENT_H
#define CALRISSIEN_2720_EVENT_H

#include "ObjectBlueprint.h"
#include "EventSpec.h"
#include <string>
#include <iostream>


/**
  * An interface for game events
  */
class Event {
 public:
  Event(std::istream& is = std::cin, std::ostream& os = std::cout);
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
  void setMessage(const std::string& m);

  /**
    * Return events message
    * @return message
    */
  const std::string& getMessage() const;

  /**
    * Set the spec. Transfers ownership to the Event.
    * @param s the spec
    */
  void setSpec(EventSpec* s);

  /**
    * Get the event's spec. Does not transfer ownership.
    * @return spec
    */
  const EventSpec* getSpec() const;

 protected:
  std::string message;
  EventSpec* spec;  // owns this object
  std::istream& in;
  std::ostream& out;

 private:
  Event(const Event&);
  Event& operator=(const Event&);
};

#endif // EVENT_H
