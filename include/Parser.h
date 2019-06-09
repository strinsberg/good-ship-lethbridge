/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_PARSER_H
#define CALRISSIEN_2720_PARSER_H

#include "Command.h"
#include <string>
class Game;


/**
  * Object responsible for parsing user inputs
  */
class Parser {
 public:
  /**
    * Create a new parser object to parse given input
    * @param in the input to parse
    * @param g The game object
    */
  Parser(std::string in, Game* g);
  virtual ~Parser();

  /**
    * Parse the input. Transfers ownership of command to the caller.
    * @return a command object for a user input command
    */
  Command* parse() const;

  /**
    * @return the input
    */
  const std::string& getInput() const;

 private:
  std::string input;
  Game* game;  // does not own this

  Parser(const Parser&);
  Parser& operator=(const Parser&);
};

#endif // PARSER_H
