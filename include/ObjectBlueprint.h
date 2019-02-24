#ifndef OBJECTBLUEPRINT_H
#define OBJECTBLUEPRINT_H

#include <string>
#include <map>

/**
  * A blueprint for object data.  Can be created from a string of object data
  * similar to a lua table. ie) "{key=value,}". Or can be built by adding
  * key value pairs to it to obtain a new string of object data. The string of
  * data to be used for creation must have a ',' at the end of every pair, even the last one.
  * All Blueprints must have a type.
  */
class ObjectBlueprint {
 public:
  ObjectBlueprint();

  /**
    * Create a blueprint from a textual representation of an object.
    * @param data a std::string of object data
    * @throws TBD if the object does not have a type.
    */
  ObjectBlueprint(const std::string& data);
  virtual ~ObjectBlueprint();

  /**
    * @return the type of the object
    */
  const std::string& getType() const;

  /**
    * @param key the name of the field to find.
    * @return the value of the field, or ObjectBlueprint::null.
    */
  const std::string& getField(const std::string& key) const;

  /**
    * @param key the name of the field.
    * @param value the value of the field.
    */
  void setField(const std::string& key, const std::string& value);

  /**
    * @return a string of object data.
    */
  std::string toString() const;

  /**
    * A constant to return for non existent fields
    */
  const std::string null = "null-field";

 private:
  std::map<std::string, std::string> record;

  /**
    * Parse a string of object data and add it's key, value pairs to record.
    * @param data a string of object data.
    */
  void parse(const std::string& data);
  ObjectBlueprint(const ObjectBlueprint&);
  ObjectBlueprint& operator=(const ObjectBlueprint&);
};

#endif // OBJECTBLUEPRINT_H
