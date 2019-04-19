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
  virtual std::string use(Entity*);
  virtual ObjectBlueprint* makeBlueprint() const;

  /**
    * See if an entity with the given name is in the container.
    * Does not transfer ownership.
    * @param name the name of the entity to search for
    * @return a pointer to the entity or nullptr
    */
  Entity* search(std::string name) const;

  Entity* searchById(std::string id) const;
  /**
    * Add an entity to the container. Transfers ownership to this container.
    * @param entity the entity to add
    */
  void addEntity(Entity* entity);

  /**
    * Remove an entity from the container. Transfers ownership to caller.
    * @param entity the entity to remove
    */
  void removeEntity(Entity* entity);

  /**
    * Find the entity that contains an object.
    * @param name the name of the object.
    * @return a pointer to the entity that contains the object.
    */
  Entity* findOwner(std::string name);

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
  Container(const Container&);
  Container& operator=(const Container&);
};

#endif // CONTAINER_H
