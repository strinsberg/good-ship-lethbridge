/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_ENTITYSPEC_H
#define CALRISSIEN_2720_ENTITYSPEC_H

#include <string>


/**
  * Holds information about an entity.
  */
class EntitySpec {
 public:
  EntitySpec();

  /**
    * Create a new EntityState with given values for the states.
    * @param id a unique string id for the Entity
    * @param name the name of the Entity
    * @param description the static description of the Entity
    */
  EntitySpec(std::string id, std::string name, std::string description);

  virtual ~EntitySpec();

  /**
    * @return the name
    */
  std::string getName() const;

  /**
    * Set the name
    * @param n the new name
    */
  void setName(std::string n);

  /**
    * @return the id
    */
  std::string getId() const;

  /**
    * Set the id
    * @param id the new id
    */
  void setId(std::string id);

  /**
    * @return the description
    */
  std::string getDescription() const;

  /**
    * set the description
    * @param d the new description
    */
  void setDescription(std::string n);

  bool matches(std::string name);

 private:
  std::string id;
  std::string name;
  std::string description;

  EntitySpec(const EntitySpec&);
  EntitySpec& operator=(const EntitySpec&);
};

#endif // ENTITYSPEC_H
