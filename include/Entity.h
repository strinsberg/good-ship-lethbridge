#ifndef CALRISSIEN_2720_ENTITY_H
#define CALRISSIEN_2720_ENTITY_H

#include "EntitySpec.h"
#include "EntityState.h"


class Entity {
public:
  Entity();
  virtual ~Entity();
  setSpec(EntitySpec*);
  setOutput(ostream&=cout);

protected:
  EntitySpec spec;
  EntityState state;
  ostream& out;

private:
  // Declare these private so that we won't have to worry about
  // Copy assignment with pointers in our objects Unless we want to
  // add it in the future. Should be same in all classes.
  Entity(const Entity&);
  Entity& operator=(const Entity&);

};

#endif // CALRISSIEN_2720_ENTITY_H
