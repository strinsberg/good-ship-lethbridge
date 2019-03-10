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
#include <vector>
class Entity;

/**
  * An interface for game events
  */
class Event {
 public:
  /**
    * Create an Event object with in and out streams
    * @param in an istream (default cin)
    * @param out an ostream (default cout)
    */
  Event(std::istream& is = std::cin, std::ostream& os = std::cout);
  virtual ~Event();

  /**
    * Resolve the event on a list of entities. Does not transfer ownership of the entities.
    * @param affected the entities to resolve the event on
    * @return a description of the results.
    */
  virtual std::string execute(Entity* affected) = 0;

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

  /**
   * Transfers ownership of spec to the event
   * @param s the new spec
   */
  void setSpec(Event* s);

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
