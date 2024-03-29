/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_COMMAND_H
#define CALRISSIEN_2720_COMMAND_H

#include <string>


/**
  * A base class for all user issued commands
  */
class Command {
 public:
  Command();
  virtual ~Command();

  /**
    * Execute the command.
    * @return a description of the result.
    */
  virtual std::string execute() = 0;

  /**
    * Set the target of the command, if applicable.
    * @param n the commands noun
    */
  virtual void setNoun(const std::string& n);

  /**
    * @return the noun
    */
  virtual const std::string& getNoun() const;

 protected:
  std::string noun;

 private:
  Command(const Command&);
  Command& operator=(const Command&);
};

#endif // COMMAND_H
