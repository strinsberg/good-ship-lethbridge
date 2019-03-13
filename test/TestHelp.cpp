/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#include "Help.h"
#include <string>
#include "gtest/gtest.h"
TEST(TestHelp,execute) {
Help h(nullptr);
EXPECT_EQ("available commands are use,get,drop,inventory,look,talk,save,load,quit and exit.",h.execute());
}
