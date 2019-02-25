#ifndef EVENTSPEC_H
#define EVENTSPEC_H


class EventSpec {
 public:
  EventSpec();
  virtual ~EventSpec() {}

  /**
    * @return the name
    */
  string getName();

  /**
    * @param n the new name
    */
  void setName(string n);

  /**
    * @return weather the event is finished or not
    */
  bool isDone();

  /**
    * @param isDone the state of the event
    */
  void setDone(bool isDone);

 protected:

 private:
  string name;
  bool done;
};

#endif // EVENTSPEC_H
