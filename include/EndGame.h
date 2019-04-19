/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef ENDGAME_H
#define ENDGAME_H

#include "Event.h"
#include <string>


/**
  * An event that ends the game successfully.
  */
class EndGame : public Event {
 public:
  EndGame(std::string id);
  virtual ~EndGame();

  std::string execute(Entity* affected);

 private:
  EndGame(const EndGame& other);
  EndGame& operator=(const EndGame& other);
};

#endif // ENDGAME_H
