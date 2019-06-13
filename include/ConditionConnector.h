#ifndef CONDITIONCONNECTOR_H
#define CONDITIONCONNECTOR_H

#include "Visitor.h"


class ConditionConnector : public Visitor {
  public:
    ConditionConnector();
    virtual ~ConditionConnector();
    ConditionConnector(const ConditionConnector& other);
    ConditionConnector& operator=(const ConditionConnector& other);

  protected:

  private:
};

#endif // CONDITIONCONNECTOR_H
