/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_ENTITY_H
#define CALRISSIEN_2720_ENTITY_H

#include "EntitySpec.h"
#include "EntityState.h"
#include "ObjectBlueprint.h"
#include "Event.h"
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
    * Use the entity. Does not transfer ownership to Entity.
    * @param user The user of the entity.
    * @return a description of the result.
    */
  virtual std::string use(Entity* user) = 0;

  /**
    * Create a blueprint of the entity that can be used to serialize it.
    * Transfers ownership of the blueprint to the caller.
    * @return the blueprint.
    */
  virtual ObjectBlueprint* makeBlueprint() const;

  /**
    * @return the spec
    */
  EntitySpec* getSpec() const;

  /**
    * Transfers ownership of spec to the entity.
    * @param s the new spec
    */
  void setSpec(EntitySpec* s);

  /**
    * @return the state
    */
  EntityState* getState() const;

  /**
    * Transfers ownership of state to the entity.
    * @param s the new state
    */
  void setState(EntityState* s);

  /**
    * Transfers ownership of event to the entity.
    * @param e the new event
    */
  void setEvent(Event* e);

  /**
    * @return the event
    */
  Event* getEvent() const;

 protected:
  EntitySpec* spec;  // owns this
  EntityState* state;  // owns this
  Event* event;  // owns this

 private:
  Entity(const Entity&);
  Entity& operator=(const Entity&);
};

#endif // CALRISSIEN_2720_ENTITY_H
