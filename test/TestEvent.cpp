/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#inlcude "Event.h"
#include "EntitySpec.h"
#include "ObjectBlueprint.h"
#include <string>

// mock for testing Event
class MockEvent : public Event {
 public:
  MockEvent() {};
  ~MockEvent() {};
  std::string execute() {return "executed";}
  ObjectBlueprint* makeBlueprint() {return new ObjectBlueprint("{type=event, message=You can't use that!}")}
};

