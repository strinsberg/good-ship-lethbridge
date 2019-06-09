#include "ConditionFactory.h"
#include "Conditional.h"
#include "json.h"

using json = nlohmann::json;


ConditionFactory::ConditionFactory() {}

ConditionFactory::~ConditionFactory() {}

Conditional* ConditionFactory::make(const json& obj) {

}
