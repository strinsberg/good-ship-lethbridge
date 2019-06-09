#ifndef DGSL_CONTAINER_H
#define DGSL_CONTAINER_H

#include "Entity.h"
#include <utility>
#include <string>
#include <map>


/**
  * Base class for all entities that can contain other entities.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-23
  */
class Container: public Entity {
 public:
  /**
    * Create a container with a given id and blank spec and state.
    * @param id a unique id.
    */
  Container(std::string id);
  virtual ~Container();

  /**
    * Give the description of the container and it's top level contents.
    */
  virtual std::string describe() const;

  /**
    * See if an entity with the given name is in the container.
    * Searches sub containers. Does not transfer ownership.
    * @param name a word or phrase that matches an entity.
    * @return a pointer to the entity or nullptr.
    */
  Entity* search(std::string name) const;

  /**
    * See if an entity with the given id is in the container.
    * Searches sub containers. Does not transfer ownership.
    * @param id the id of the entity to search for.
    * @return a pointer to the entity or nullptr.
    */
  Entity* searchById(std::string id);

  /**
    * Add an entity to the container. Transfers ownership to this container.
    * @param entity the entity to add
    */
  void addEntity(Entity* entity);

  /**
    * Remove an entity from the container. Does not go into sub containers.
    * Use this when you already have a pointer to the container and the
    * entity. Use searchAndRemove if you have an entity id and you don't know
    * for sure that it is in the container (in a sub container).
    * @param entity a pointer to the entity to remove
    */
  void removeEntity(Entity* entity);

  /**
    * Remove an entity from the container, if it is there. Transfers ownership.
    * Searches and removes from sub containers. Use this when you want to look
    * for an entity by id in a container and then remove it. You don't need to
    * know if it is in a sub container.
    * @param id the id of the entity to remove.
    * @return the entity or nullptr.
    */
  Entity* searchAndRemove(std::string id);

  /**
    * Returns an iterator to the beginning of inventory.
    * @return a map iterator to beginning of the containers inventory.
    */
  std::map<std::string, Entity*>::iterator begin();

  /**
    * Returns an iterator to the end of inventory.
    * @return a map iterator to end of the containers inventory.
    */
  std::map<std::string, Entity*>::iterator end();

 protected:
  /**
    * Storage for all the entities in the container. Key is entity id.
    * These are owned by the container.
    */
  std::map<std::string, Entity*> inventory;

 private:
  std::pair<Container*, Entity*> findEntity(std::string id);

  Container(const Container&);
  Container& operator=(const Container&);
};

#endif // CONTAINER_H
