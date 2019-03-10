/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */


#include "Talk.h"
#include <string>


Talk::Talk() {}
Talk::~Talk() {}
std::string Talk::execute() {
  return noun;
}
