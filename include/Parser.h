/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_PARSER_H
#define CALRISSIEN_2720_PARSER_H

#include "Command.h"
#include <string>


/**
  * Object responsible for parsing user inputs
  */
class Parser {
 public:
  /**
    * Create a new parser object to parse given input
    * @param in the input to parse
    */
  Parser(std::string in);
  virtual ~Parser();

  /**
    * Parse the input. Transfers ownership of command to the caller.
    * @return a command object for a user input command
    */
  Command* parse() const;

 private:
  std::string input;

  Parser(const Parser&);
  Parser& operator=(const Parser&);
};

#endif // PARSER_H
