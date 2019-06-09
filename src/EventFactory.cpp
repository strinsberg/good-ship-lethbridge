/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-21
 */

#include "EventFactory.h"
#include "Exceptions.h"
#include "Inform.h"
#include "Kill.h"
#include "Interaction.h"
#include "EventGroup.h"
#include "StructuredEvents.h"
#include "ConditionalEvent.h"
#include "TransferItem.h"
#include "ToggleActive.h"
#include "Door.h"
#include "MovePlayer.h"
#include "EquipSuit.h"
#include "Conditional.h"
#include "Question.h"
#include "Protected.h"
#include "HasItem.h"
#include "Atmosphere.h"
#include <string>
#include <iostream>

bool stob(const std::string& str) {
  return str == "true";
}

Atmosphere sToAtmos(std::string& str) {
  if (str == "radiation")
    return Atmosphere::RADIATION;
  else if (str == "space")
    return Atmosphere::SPACE;
  else
    return Atmosphere::OXYGEN;
}

EventFactory::~EventFactory() {}


Event* EventFactory::makeEvent(const json& obj) {

}

EventGroup* EventFactory::makeGroup(const json& obj) {

}
