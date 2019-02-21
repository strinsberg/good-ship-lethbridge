#ifndef CALRISSIEN_2720_COMMAND_H
#define CALRISSIEN_2720_COMMAND_H

#include <iostream>

class Command
{
  public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;

    virtual void setOutput(ostream&);

  protected:
    ostream& out;

  private:
    Command(const Command&);
    Command& operator=(const Command&);
};

#endif // COMMAND_H
