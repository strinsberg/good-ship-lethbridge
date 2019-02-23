/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_COMMAND_H
#define CALRISSIEN_2720_COMMAND_H

#include <string>


/**
  * An interface for all user issued commands
  */
class Command {
 public:
  Command() : out(nullptr) {}
  virtual ~Command() {}

  /**
    * Execute the command.
    * @return a description of the result.
    */
  virtual std::string execute() = 0;

  /**
    * Set the target of the command, if applicable.
    * @param n the commands noun
    */
  void setNoun(const std::string& n);

 protected:
  std::string noun;

 private:
  Command(const Command&);
  Command& operator=(const Command&);
};

#endif // COMMAND_H
