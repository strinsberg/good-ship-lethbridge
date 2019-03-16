/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#ifndef CALRISSIEN_2720_OBJECT_BLUEPRINT_H
#define CALRISSIEN_2720_OBJECT_BLUEPRINT_H

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
    * @throw TBD if the object does not have a type.
    */
  ObjectBlueprint(const std::string& data);
  virtual ~ObjectBlueprint();

  /**
    * @return the type of the object, ObjectBlueprint::null if no type
    */
  std::string getType() const;

  /**
    * @param key the name of the field to find.
    * @return the value of the field, or ObjectBlueprint::null.
    */
  std::string getField(const std::string& key) const;

  /**
    * @param key the name of the field.
    * @param value the value of the field.
    * @return true if the pair is added, false if the key is already set.
    */
  bool setField(const std::string& key, const std::string& value);

  /**
    * @return a string of object data.
    * @throw TBD if the object does not have a type
    */
  virtual std::string toString() const;

  /**
    * A constant to return for non existent fields
    */
  static std::string null();

 private:
  std::map<std::string, std::string> record;

  /**
    * Parse a string of object data and add it's key, value pairs to record.
    * @param data a string of object data.
    */
  void parse(const std::string& data);

  size_t skipWhitespace(const std::string& str, size_t pos);
  std::string toLower(const std::string& str);

  ObjectBlueprint(const ObjectBlueprint&);
  ObjectBlueprint& operator=(const ObjectBlueprint&);
};

#endif // OBJECTBLUEPRINT_H
