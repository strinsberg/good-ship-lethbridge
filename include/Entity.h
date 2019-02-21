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

};

#endif // CALRISSIEN_2720_ENTITY_H
