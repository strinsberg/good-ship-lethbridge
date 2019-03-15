/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#ifndef ENDGAME_H
#define ENDGAME_H

#include "Event.h"
#include <string>


class EndGame : public Event {
 public:
  EndGame();
  virtual ~EndGame();

  std::string execute(Entity* affected);
  ObjectBlueprint* makeBlueprint() const;

 private:
  EndGame(const EndGame& other);
  EndGame& operator=(const EndGame& other);
};

#endif // ENDGAME_H
