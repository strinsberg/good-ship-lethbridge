#ifndef DGSL_ENTITYSPEC_H
#define DGSL_ENTITYSPEC_H

#include <string>


/**
  * Holds information about an entity.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-25
  */
class EntitySpec {
  public:
    /**
      * Create a new EntityState with given values for the states.
      * @param id a unique id.
      * @param name a name.
      * @param description a description.
      */
    EntitySpec(std::string id, std::string name, std::string description);

    virtual ~EntitySpec();

    /**
      * Returns the name.
      * @return the name.
      */
    std::string getName() const;

    /**
      * Sets the name.
      * @param name the new name.
      */
    void setName(std::string nname);

    /**
      * Returns the id.
      * @return the id.
      */
    std::string getId() const;

    /**
      * Sets the id.
      * @param id the new id.
      */
    void setId(std::string id);

    /**
      * Returns the description.
      * @return the description.
      */
    std::string getDescription() const;

    /**
      * Sets the description.
      * @param description the new description.
      */
    void setDescription(std::string description);

    /**
      * Checks to see if the given word or phrase is contained in the
      * name or the description. Will match the noun exactly.
      * @param noun a word or phrase.
      * @return true if the word or phrase appears in the name
      * or the description, false otherwise.
      */
    bool matches(std::string noun);

  private:
    std::string id;
    std::string name;
    std::string description;

    EntitySpec(const EntitySpec&);
    EntitySpec& operator=(const EntitySpec&);
};

#endif // ENTITYSPEC_H
