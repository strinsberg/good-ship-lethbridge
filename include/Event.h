#ifndef CALRISSIEN_2720_EVENT_H
#define CALRISSIEN_2720_EVENT_H


/**
  * An interface for game events
  */
class Event
{
  public:
    Event();
    virtual ~Event();
    virtual void execute() = 0;

    /**
      * Set the message to be displayed when the event is executed
      * @param m the message
      */
    void setMessage(string m);

    /**
      * @param os the new output stream
      */
    void setOutput(ostream& os);

  protected:
    string message;
    ostream& out;

  private:
    Event(const Event&);
    Event& operator=(const Event&);
};

#endif // EVENT_H
