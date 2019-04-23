#ifndef DGSL_COMMAND_H
#define DGSL_COMMAND_H

#include <string>


/**
  * A base class for processing all user issued commands.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-23
  */
class Command {
 public:
  /**
    * Creates a command with a given noun.
    * @param noun a single word or compund phrase representing a game object.
    * Defaults to empty.
    */
  Command(std::string noun = "");
  virtual ~Command();

  /**
    * Execute the command on the player and the noun.
    * @return a textual description of the result.
    */
  virtual std::string execute() = 0;

  /**
    * Set the noun for the command to act on.
    * @param noun a single word or compund phrase representing a game object.
    */
  void setNoun(std::string noun);

  /**
    * Returns the noun.
    * @return the noun
    */
  std::string getNoun() const;

 protected:
  std::string noun;  /**< The object for the command to act on */

 private:
  Command(const Command&);
  Command& operator=(const Command&);
};

#endif // COMMAND_H
