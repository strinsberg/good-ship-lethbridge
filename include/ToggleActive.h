/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef TOGGLEACTIVE_H
#define TOGGLEACTIVE_H

#include "Event.h"
#include "EventVisitor.h"


class ToggleActive : public Event {
  public:
    ToggleActive(std::string id) : Event(id), target(nullptr) {}
    ToggleActive(std::string id, Entity* target, bool oneTime=true);
    virtual ~ToggleActive();

    std::string execute(Entity* affected);
    void setTarget(Entity* e) {
        target = e;
    }

    void accept(EventVisitor& v) {
        v.visit(this);
    }

  protected:
    Entity* target;
    bool once;

  private:
    ToggleActive(const ToggleActive& other);
    ToggleActive& operator=(const ToggleActive& other);
};

#endif // TOGGLEACTIVE_H
