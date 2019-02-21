#ifndef CALRISSIEN_2720_PARSER_H
#define CALRISSIEN_2720_PARSER_H


class Parser
{
  public:
    Parser(string);
    virtual ~Parser();
    Command* parse();

  protected:

  private:
    string input;

    Parser(const Parser&);
    Parser& operator=(const Parser&);
};

#endif // PARSER_H
