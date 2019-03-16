/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-27
 */

#ifndef CALRISSIEN_2720_OBJECT_WITH_CONTENTS_BLUEPRINT_H
#define CALRISSIEN_2720_OBJECT_WITH_CONTENTS_BLUEPRINT_H

#include "ObjectBlueprint.h"
#include <vector>
#include <string>


/**
  * An object to use when creating a blueprint of an object that is
  * holding or composed of other objects that also have blueprints
  */
class ObjectWithContentsBlueprint : public ObjectBlueprint {
 public:
  ObjectWithContentsBlueprint();
  ObjectWithContentsBlueprint(const std::string& data);
  virtual ~ObjectWithContentsBlueprint();

  /**
    * Add an ObjectBlueprint to the contents. Transfers ownership.
    * @param obj an ObjectBlueprint
    */
  void addBlueprint(ObjectBlueprint* obj);

  /**
    * @return an iterator to the beginning of the contents
    */
  const std::vector<ObjectBlueprint*>::iterator begin();

  /**
    * @return an iterator to the end of the contents
    */
  const std::vector<ObjectBlueprint*>::iterator end();

  /**
  * @return a string of object data.
  */
  std::string toString() const;

 private:
  std::vector<ObjectBlueprint*> contents;  // owns these objects

  ObjectWithContentsBlueprint(const ObjectWithContentsBlueprint&);
  ObjectWithContentsBlueprint& operator=(const ObjectWithContentsBlueprint&);
};

#endif // OBJECTWITHCONTENTSBLUEPRINT_H
