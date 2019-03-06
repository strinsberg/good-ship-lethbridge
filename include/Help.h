#ifndef HELP_H
#define HELP_H

#include "GameCommand.h"
#include <string>


/**
  * Command to get help.
  */
class Help : public GameCommand
{
  public:
    Help();
    virtual ~Help();

   std::string execute();

  private:
    Help(const Help& other);
    Help& operator=(const Help& other);
};

#endif // HELP_H
