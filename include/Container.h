/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_CONTAINER_H
#define CALRISSIEN_2720_CONTAINER_H

#include "Entity.h"
#include <map>


/**
  * Base class for all entities that can contain other entities
  */
class Container: public Entity {
 public:
  Container();
  virtual ~Container();
  void describe() const;
  void use(Entity&);
  void serialize(std::fstream&) const;

  /**
    * See if an entity with the given name is in the container.
    * Does not transfer ownership.
    * @param name the name of the entity to search for
    * @return a pointer to the entity or nullptr
    */
  Entity* search(std::string name) const;

  /**
    * Add an entity to the container. Transfers ownership to this container.
    * @param entity the entity to add
    */
  void addEntity(Entity* entity);

  /**
    * Remove an entity from the container. Transfers ownership to caller.
    * @param entity the entity to remove
    */
  Entity* removeEntity(Entity& entity);

 protected:
  std::map<std::string, Entity*> inventory;  // owns the entities it contains

 private:
  Container(const Container&);
  Container& operator=(const Container&);
};

#endif // CONTAINER_H
