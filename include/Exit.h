#ifndef CALRISSIEN_2720_EXIT_H
#define CALRISSIEN_2720_EXIT_H

#include "Action.h"


class Exit : public Action
{
  public:
    Exit() {}
    virtual ~Exit() {}

    void execute();

  protected:

  private:
    Exit(const Exit&);
    Exit& operator=(const Exit&);
};

#endif // EXIT_H
