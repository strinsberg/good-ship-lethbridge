/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_GAME_H
#define CALRISSIEN_2720_GAME_H

#include "Room.h"
#include "Player.h"
#include "Event.h"
#include <string>
#include <map>
#include <iostream>


/**
  * Object responsible for running the game
  */
class Game {
  public:
    Game(std::istream& is = std::cin, std::ostream& os = std::cout);
    virtual ~Game();

    /**
      * Run the main game loop
      */
    void run();

    /**
      * Does not Transfer ownership
      * @return the player
      */
    Player* getPlayer() const;

    /**
      * Set the player for the game. Transfers ownership to this game.
      * @param p the new player character
      */
    void setPlayer(Player* p);

    /**
      * Get a pointer to a room with a given name. Does not transfer ownership.
      * @param name the name of the room
      * @return the room with given name or nullptr
      */
    Room* getRoom(const std::string& name);

    /**
      * Add a room to the game. Transfers ownership to this game.
      * @param name the name of the room. (probably change later
      * when room is implemented)
      * @param room the room to add
      * @throws invalid_parameter_error if a room with same name is
      * already stored
      */
    void addRoom(const std::string& name, Room* room);

    /**
      * @return the number of rooms
      */
    int numRooms();

    /**
      * Returns wether the game is running or not.
      * @return running
      */
    bool isRunning();

    /**
      * Sets running to false
      */
    void stop();

    /**
      * Returns an event by name from the list of game events. Does not transfer
      * ownership of the event.
      * @param name the name of the event
      * @return a pointer to the event
      */
    Event* getEvent(const std::string& id);

    /**
      * Adds an event by it's name to the games events. Does not Transfer
      * ownership to the Game.
      * @param name the events name
      * @param event the event to add
      */
    void addEvent(const std::string& id, Event* event);

    /**
      * Returns the map of the games rooms
      */
    std::map<std::string, Room*>& getRooms();

    /**
      * Makes all the characters in a string lowercase.
      * @param str the string to make lowercase.
      * @return a new lowercase version of the string.
      */
    static std::string toLower(const std::string& str);

    void updateEntity(ObjectBlueprint*);
    void updateEvent(ObjectBlueprint*);
    void updateInteraction(ObjectBlueprint*);
    void moveEntity(Entity*, std::string);

    static bool stob(const std::string& str);

    void setEvents(std::map<std::string, Event*> e) {
        events = e;
    }
    void setEntities(std::map<std::string, Entity*> e) {
        entities = e;
    }
    void setConditions(std::map<std::string, Conditional*> c) {
        conditions = c;
    }

    void setName(std::string n) {
        name = n;
    }
    void setWelcome(std::string w) {
        welcome = w;
    }
    void setVersion(std::string v) {
        version = v;
    }

    Entity* getEntity(const std::string& id);
    void addEntity(const std::string& id, Entity* entity);

    Conditional* getConditional(const std::string& id);
    void addConditional(const std::string& id, Conditional* condition);

  private:
    std::map<std::string, Room*> rooms;  // owns rooms
    std::map<std::string, Event*> events; // !!!does not own these!!!
    Player* player;  // owns player
    std::istream& in;
    std::ostream& out;
    bool running;

    std::map<std::string, Entity*> entities;
    std::map<std::string, Conditional*> conditions;
    std::string name;
    std::string welcome;
    std::string version;

    Game(const Game&);
    Game& operator=(const Game&);
};

#endif // GAME_H
