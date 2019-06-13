#ifndef DGSL_CONDITIONALEVENT_H
#define DGSL_CONDITIONALEVENT_H

#include "Event.h"
#include "Conditional.h"
#include <string>


/**
  * An composite event that tests the affected entity to see if it satisfies a
  * given condition. Based on the result of the condition a different event is
  * executed. It is permissible to leave the failure event null.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>
  * @date 2019-04-19
  */
class ConditionalEvent : public Event {
  public:
    /**
      * Creates a conditional event with a given id and null conditions
      * and events.
      * @param id the events unique id.
      */
    ConditionalEvent(std::string id);
    virtual ~ConditionalEvent();

    /**
      * Set the condition of the event. Transfers ownership.
      * @param condition a pointer to a Conditional.
      */
    void setCondition(Conditional* condition);

    /**
      * Set the event to execute when the condition is true.
      * Transfers ownership.
      * @param success the event to run when condition is true.
      */
    void setSuccess(Event* success);

    /**
      * Set the event to execute when the condition is false.
      * Transfers ownership.
      * @param failure the event to run when condition is false.
      */
    void setFailure(Event* failure);

    std::string execute(Entity* affected);

  private:
    Conditional* condition;  //owns this
    Event* success;  // owns this
    Event* failure;  // owns this

    ConditionalEvent(const ConditionalEvent&);
    ConditionalEvent& operator=(const ConditionalEvent&);
};

#endif // CONDITIONALEVENT_H
