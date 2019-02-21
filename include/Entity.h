#ifndef CALRISSIEN_2720_ENTITY_H
#define CALRISSIEN_2720_ENTITY_H

#include "EntitySpec.h"
#include "EntityState.h"
#include <iostream>


class Entity {
public:
  Entity();
  virtual ~Entity();
  virtual void describe() = 0;
  virtual void use(Entity&) = 0;
  virtual void serialize(fstream&) = 0;

  EntitySpec& getSpec();
  void setSpec(EntitySpec*);
  EntityState& getState();
  void setState(EntityState*);
  void setOutput(ostream&);

protected:
  EntitySpec spec;
  EntityState state;
  ostream& out;  // default to cout

private:
  // Declare these private so that we won't have to worry about
  // Copy assignment with pointers in our objects Unless we want to
  // add it in the future. Should be same in all classes.
  Entity(const Entity&);
  Entity& operator=(const Entity&);

};

#endif // CALRISSIEN_2720_ENTITY_H
