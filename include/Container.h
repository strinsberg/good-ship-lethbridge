#ifndef CALRISSIEN_2720_CONTAINER_H
#define CALRISSIEN_2720_CONTAINER_H

#include "Entity.h"
#include <map>


/**
  * Base class for all entities that can contain other entities
  */
class Container: public Entity
{
  public:
    Container();
    virtual ~Container();
    void describe();
    void use(Entity&);
    void serialize(fstream&);

    /**
      * See if an entity with the given name is in the container.
      * Does not transfer ownership.
      * @param name the name of the entity to search for
      * @return a pointer to the entity or nullptr
      */
    Entity* search(string name);

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
    map<string, Entity*> inventory;  // owns the entities it contains

  private:
    Container(const Container&);
    Container& operator=(const Container&);
};

#endif // CONTAINER_H
