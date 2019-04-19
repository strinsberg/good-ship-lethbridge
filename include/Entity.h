/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_ENTITY_H
#define CALRISSIEN_2720_ENTITY_H

#include "Serializable.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "ObjectBlueprint.h"
#include "Event.h"
#include <string>
#include <map>


/**
  * Abstract class for a base game entity.
  */
class Entity : public Serializable {
 public:
  Entity();
  virtual ~Entity();

  /**
    * @return a description of the entity.
    */
  virtual std::string describe() const;

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

  void serialize(std::ostream& out) {out << "temp";}

  void addEvent(std::string verb, Event* event);
  std::string runEvent(std::string verb, Entity* user);
  bool matches(std::string name);

 protected:
  EntitySpec* spec;  // owns this
  EntityState* state;  // owns this
  std::map<std::string, Event*> events;  // owns these

 private:
  Entity(const Entity&);
  Entity& operator=(const Entity&);
};

#endif // CALRISSIEN_2720_ENTITY_H
