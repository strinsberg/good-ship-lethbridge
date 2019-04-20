/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef TOGGLEACTIVE_H
#define TOGGLEACTIVE_H

#include "OwnedEvent.h"


class ToggleActive : public OwnedEvent
{
  public:
    ToggleActive(std::string id, Entity* owner, bool oneTime=true);
    virtual ~ToggleActive();

    std::string execute(Entity* target);

  protected:
    bool once;

  private:
    ToggleActive(const ToggleActive& other);
    ToggleActive& operator=(const ToggleActive& other);
};

#endif // TOGGLEACTIVE_H
