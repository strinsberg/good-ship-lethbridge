/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-5
 */

#ifndef EVENTSPEC_H
#define EVENTSPEC_H

#include <string>

/**
  * Holds some general info and state for an event.
  */
class EventSpec {
 public:
  EventSpec();
  virtual ~EventSpec();

  /**
    * Set if the event is done or not.
    * @param d if the event is done
    */
  void setDone(bool d);

  /**
    * Get the status of the event
    * @return done
    */
  bool isDone() const;

  /**
    * Set the name of the event
    * @param n the name
    */
  void setName(const std::string& n);

  /**
    * Get the name of the event
    * @return the name
    */
  const std::string& getName() const;

 private:
  bool done;
  std::string name;

  EventSpec(const EventSpec& other);
  EventSpec& operator=(const EventSpec& other);
};

#endif // EVENTSPEC_H
