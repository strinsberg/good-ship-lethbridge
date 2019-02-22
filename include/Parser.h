/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_PARSER_H
#define CALRISSIEN_2720_PARSER_H


/**
  * Object responsible for parsing user inputs
  */
class Parser {
 public:
  /**
    * Create a new parser object to parse given input
    * @param in the input to parse
    */
  Parser(string in);
  virtual ~Parser();

  /**
    * Parse the input. Transfers ownership to the caller.
    * @return a command object for a user input command
    * @throws invalid_input_error if the input does not make sense
    */
  Command* parse() const;

 private:
  string input;

  Parser(const Parser&);
  Parser& operator=(const Parser&);
};

#endif // PARSER_H
