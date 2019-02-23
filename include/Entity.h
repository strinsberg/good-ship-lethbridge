/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_ENTITY_H
#define CALRISSIEN_2720_ENTITY_H

#include "EntitySpec.h"
#include "EntityState.h"
#include "ObjectBlueprint.h"
#include <string>


/**
  * Abstract class for a base game entity.
  */
class Entity {
 public:
  Entity();
  virtual ~Entity();

  /**
    * @return a description of the entity.
    */
  virtual std::string describe() const = 0;

  /**
    * Use the entity.
    * @param user The user of the entity.
    * @return a description of the result.
    */
  virtual std::string use(Entity& user) = 0;

  /**
    * Create a blueprint of the entity that can be used to serialize it.
    * Transfers ownership of the blueprint to the caller.
    * @return the blueprint.
    */
  virtual ObjectBlueprint* makeBlueprint() const = 0;

  /**
    * @return the spec
    */
  EntitySpec& getSpec() const;

  /**
    * Transfers ownership of spec to the entity.
    * @param s the new spec
    */
  void setSpec(EntitySpec* s);

  /**
    * @return the state
    */
  EntityState& getState() const;

  /**
    * Transfers ownership of state to the entity.
    * @param s the new state
    */
  void setState(EntityState* s);

 protected:
  EntitySpec* spec;  // owns this
  EntityState* state;  // owns this

 private:
  Entity(const Entity&);
  Entity& operator=(const Entity&);

};

#endif // CALRISSIEN_2720_ENTITY_H
