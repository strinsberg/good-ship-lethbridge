#ifndef CALRISSIEN_2720_COMMAND_H
#define CALRISSIEN_2720_COMMAND_H

#include <iostream>


/**
  * An interface for all user issued commands
  */
class Command
{
  public:
    Command();
    virtual ~Command();

    /**
      * Execute the command
      */
    virtual void execute() = 0;

    /**
      * @param os the new output stream
      */
    virtual void setOutput(ostream& os);

  protected:
    ostream& out;

  private:
    Command(const Command&);
    Command& operator=(const Command&);
};

#endif // COMMAND_H
