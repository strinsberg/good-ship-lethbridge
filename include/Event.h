#ifndef CALRISSIEN_2720_EVENT_H
#define CALRISSIEN_2720_EVENT_H


class Event
{
  public:
    Event();
    virtual ~Event();
    virtual void execute() = 0;

    void setMessage(string);
    void setOutput(ostream&);

  protected:
    string message;
    ostream& out;

  private:
    Event(const Event&);
    Event& operator=(const Event&);
};

#endif // EVENT_H
