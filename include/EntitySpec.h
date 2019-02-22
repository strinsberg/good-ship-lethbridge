/*
 * CPSC2720 Group Project Spring 2019
 * Steven Deutekom <deutekom@uleth.ca>
 * Max Niu <max.niu@uleth.ca>
 */

#ifndef CALRISSIEN_2720_ENTITYSPEC_H
#define CALRISSIEN_2720_ENTITYSPEC_H


/**
  * Holds information about an entity
  */
class EntitySpec {
 public:
  EntitySpec();
  virtual ~EntitySpec();

  /**
    * Check to see if this spec matches a name
    * @param n the name to check
    * @return true if it is a match, otherwise false
    */
  bool matches(string) const;

  /**
    * @return the name
    */
  string getName() const;

  /**
    * Set the name
    * @param n the new name
    */
  void setName(string);

  /**
    * @return the description
    */
  string getDescription() const;

  /**
    * set the description
    * @param d the new description
    */
  void setDescription(string);

 private:
  string name;
  string description;

  EntitySpec(const EntitySpec&);
  EntitySpec& operator=(const EntitySpec&);
};

#endif // ENTITYSPEC_H
