/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05, 2019-03-14
 */

#include "Save.h"
#include "Game.h"
#include <string>
#include <sstream>
#include <fstream>

std::string hash_name(const std::string&);

Save::Save(Game* g) :GameCommand(g) {}

Save::~Save() {}

std::string Save::execute() {
    return "Game saved!!!";
}


std::string hash_name(const std::string& name) {
    int hash = 0;
    for (auto c : name) {
        hash += c;
    }
    std::stringstream ss;
    ss << hash;
    return ss.str();
}
