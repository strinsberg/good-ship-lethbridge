#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>


/**
  * An object to hold game data and to iterate over the
  * object data contained in it.
  */
class GameData {
 public:
  /**
    * Create a game data object from a string of game data.
    */
  GameData(const std::string& gdata);
  virtual ~GameData();

  /**
    * Get the next string of object data and returns it.
    * The object data string is the kind used by ObjectBlueprint.
    * @return the next string of object data, or GameData::eof
    */
  std::string nextObject();

  /**
    * @return begin
    */
  size_t getBegin() const;

  /**
    * @return end
    */
  size_t getEnd() const;

  /**
    * @return the data
    */
  const std::string& getData() const;

  /**
    * The end of the game data.
    */
  static const std::string eof;

 private:
  std::string data;  // String of game data
  size_t begin;  // beginning of the next string of object data
  size_t end;  //end of the next string of object data
};


#endif // GAMEDATA_H
