#ifndef CALRISSIEN_2720_DROP_H
#define CALRISSIEN_2720_DROP_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to drop a game object.
  */
class Drop : public Action
{
  public:
    Drop(Player* p);
    virtual ~Drop();

    std::string execute();

  protected:

  private:
    Drop(const Drop& other);
    Drop& operator=(const Drop& other);
};

#endif // DROP_H
