#ifndef CONDITIONFACTORY_H
#define CONDITIONFACTORY_H

#include "Conditional.h"
#include "json.h"

using json = nlohmann::json;

class ConditionFactory
{
    public:
        ConditionFactory();
        virtual ~ConditionFactory();

        Conditional* make(const json& obj);

    private:

        ConditionFactory(const ConditionFactory& other);
        ConditionFactory& operator=(const ConditionFactory& other);
};

#endif // CONDITIONFACTORY_H
