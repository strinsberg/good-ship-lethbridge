#ifndef CALRISSIEN_2720_ENTITY_H
#define CALRISSIEN_2720_ENTITY_H

#include "EntitySpec.h"
#include "EntityState.h"
#include <iostream>


/**
  * Interface for a base game entity.
  */
class Entity {
public:
  /**
    * Display a description of the entity to the
    * entity's output stream.
    */
  virtual void describe() = 0;

  /**
    * Use the entity.
    * @param user The user of the entity.
    */
  virtual void use(Entity& user) = 0;

  /**
    * Write the entities details to a file.
    * @param fout The file stream to write to.
    */
  virtual void serialize(fstream& fout) = 0;

  /**
    * @return the spec
    */
  EntitySpec& getSpec();

  /**
    * Transfers ownership of state to the entity.
    * @param s the new spec
    */
  void setSpec(EntitySpec* s);

  /**
    * @return the state
    */
  EntityState& getState();

  /**
    * Transfers ownership of state to the entity.
    * @param s the new state
    */
  void setState(EntityState* s);

  /**
    * @param os the new output stream
    */
  void setOutput(ostream& os);

protected:
  EntitySpec* spec;  // owns this
  EntityState* state;  // owns this
  ostream& out;  // default to cout in constructor

private:

};

#endif // CALRISSIEN_2720_ENTITY_H
