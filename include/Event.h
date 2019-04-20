/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-04-19
 */

#ifndef CALRISSIEN_2720_EVENT_H
#define CALRISSIEN_2720_EVENT_H

#include "Serializable.h"
#include "ObjectBlueprint.h"
#include <string>
#include <iostream>
#include <vector>
class Entity;

/**
  * Base class for all game events
  */
class Event : public Serializable {
 public:
  /**
    * Creates an event with a given ID.
    * @param id a unique string id
    */
  Event(std::string id);
  virtual ~Event();

  /**
    * Execute the event on the given entity. Does not transfer ownership of the entities.
    * @param affected the entity affected by the event
    * @return a description of the results.
    */
  virtual std::string execute(Entity* affected);

  void serialize(std::ostream& out) {out << "temp";}

  std::string getId() const;
  bool isDone() const;
  void setDone(bool done);
  void subscribe(Event*);

 protected:
  std::string id;
  bool done;
  std::vector<Event*> observers;  // does not own these

 private:
  Event(const Event&);
  Event& operator=(const Event&);
};

#endif // EVENT_H
