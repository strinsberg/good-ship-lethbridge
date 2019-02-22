/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_COMMAND_H
#define CALRISSIEN_2720_COMMAND_H

#include <iostream>


/**
  * An interface for all user issued commands
  */
class Command {
 public:
  Command() : out(nullptr) {}
  virtual ~Command() {}

  /**
    * Execute the command
    */
  virtual void execute() = 0;

  /**
   * @param n the target of the command
   */
  void setNoun(std::string n) {
    noun = n;
  }

  /**
   * @param os the output stream for the command to write to
   */
  void setOutput(std::ostream* os) {
    out = os;
  }

 protected:
  std::string noun;
  std::ostream* out;

 private:
  Command(const Command&);
  Command& operator=(const Command&);
};

#endif // COMMAND_H
