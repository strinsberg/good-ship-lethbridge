/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_CONTAINER_H
#define CALRISSIEN_2720_CONTAINER_H

#include "Entity.h"
#include "ObjectBlueprint.h"
#include <string>
#include <map>


/**
  * Base class for all entities that can contain other entities
  */
class Container: public Entity {
 public:
  Container();
  virtual ~Container();

  /**
    * Give the description of the container and everything it has in it.
    */
  virtual std::string describe() const;

  /**
    * See if an entity with the given name is in the container.
    * Searches sub containers. Does not transfer ownership.
    * @param name the name of the entity to search for
    * @return a pointer to the entity or nullptr
    */
  Entity* search(std::string name) const;

  /**
    * See if an entity with the given id is in the container.
    * Searches sub containers. Does not transfer ownership.
    * @param id the id of the entity to search for
    * @return a pointer to the entity or nullptr
    */
  Entity* searchById(std::string id);

  /**
    * Add an entity to the container. Transfers ownership to this container.
    * @param entity the entity to add
    */
  void addEntity(Entity* entity);

  /**
    * Remove an entity from the container. Transfers ownership to caller.
    * Does not go into sub containers.
    * @param entity the entity to remove
    */
  void removeEntity(Entity* entity);

  /**
    * Remove an entity from the container, if it is there. Transfers ownership.
    * Searches and removes from sub containers.
    * @param id the id of the entity to remove
    * @return the entity or nullptr
    */
  Entity* searchAndRemove(std::string id);

  /**
    * Returns an iterator to the beginning of inventory.
    * @return a amp iterator to beginning of the containers inventory.
    */
  std::map<std::string, Entity*>::iterator begin();

  /**
    * Returns an iterator to the end of inventory.
    * @return a amp iterator to end of the containers inventory.
    */
  std::map<std::string, Entity*>::iterator end();

 protected:
  std::map<std::string, Entity*> inventory;  // owns the entities it contains

 private:
  std::pair<Container*, Entity*> findEntity(std::string id);

  Container(const Container&);
  Container& operator=(const Container&);
};

#endif // CONTAINER_H
