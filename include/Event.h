/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_EVENT_H
#define CALRISSIEN_2720_EVENT_H

#include <string>


/**
  * An interface for game events
  */
class Event {
 public:
  Event();
  virtual ~Event();
  virtual void execute() = 0;

  /**
    * Set the message to be displayed when the event is executed
    * @param m the message
    */
  void setMessage(std::string m);

  /**
    * @param os the new output stream
    */
  void setOutput(std::ostream* os) {out = os;};

 protected:
  std::string message;
  std::ostream* out;

 private:
  Event(const Event&);
  Event& operator=(const Event&);
};

#endif // EVENT_H
