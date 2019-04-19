/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef CONDITIONALEVENT_H
#define CONDITIONALEVENT_H

#include "Event.h"
#include "Conditional.h"


class ConditionalEvent : public Event
{
  public:
    ConditionalEvent(std::string id);
    virtual ~ConditionalEvent();

    void setCondition(Conditional*);
    void setSuccess(Event*);
    void setFailure(Event*);

    std::string execute(Entity*);

  private:
    Conditional* condition;  //owns this
    Event* success;  // owns this
    Event* failure;  // owns this

    ConditionalEvent(const ConditionalEvent& other);
    ConditionalEvent& operator=(const ConditionalEvent& other);
};

#endif // CONDITIONALEVENT_H
