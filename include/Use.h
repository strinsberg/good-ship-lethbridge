/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_USE_H
#define CALRISSIEN_2720_USE_H

#include "Action.h"
#include "Player.h"
#include <string>


/**
  * Action to use a game object.
  */
class Use : public Action {
 public:
  Use(Player* p);
  virtual ~Use();

  std::string execute();

 private:
  Use(const Use& other);
  Use& operator=(const Use& other);
};

#endif // USE_H
