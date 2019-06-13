#ifndef DGSL_ENTITY_H
#define DGSL_ENTITY_H

#include "Serializable.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Event.h"
#include "Visitor.h"
#include <string>
#include <map>


/**
  * Base class for all game entities.
  *
  * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
  * @date 2019-03-05, 2019-04-22
  */
class Entity : public Serializable {
  public:
    /**
      * Create an entity with blank spec and default state.
      */
    Entity();

    /**
      * Create an entity with a given id and a blank spec and default state.
      * @param id a unique id.
      */
    Entity(std::string id);
    virtual ~Entity();

    /**
      * Return a description of the entity.
      * @return a description of the entity.
      */
    virtual std::string describe() const;

    /**
      * Return a pointer to the entities spec. Does not transfer ownership.
      * @return a pointer to the spec
      */
    EntitySpec* getSpec() const;

    /**
      * Set the entities spec. Transfers ownership.
      * @param s the new spec
      */
    void setSpec(EntitySpec* s);

    /**
      * Return a pointer to the entity's state. Does not transfer ownership.
      * @return a pointer to the state.
      */
    EntityState* getState() const;

    /**
      * Set the entity's state. Transfers ownership.
      * @param s the new state
      */
    void setState(EntityState* s);

    // default until all serialize methods can be properly overridden
    // documentation will be in serialize class
    void serialize(std::ostream& out) {
        out << "temp";
    }

    /**
      * Add an event to the entity under a given verb. Transfers ownership.
      * Will replace a previously existing event with the given verb.
      * @param verb the verb to associate the event with.
      * @param event the event to add.
      */
    void addEvent(std::string verb, Event* event);

    /**
      * Execute an event for a given verb.
      * @param verb the verb of the event.
      * @param affected the entity affected by the event.
      * @param return a description of the result or "Nothing happens" if there
      * is no event for the given verb.
      */
    std::string runEvent(std::string verb, Entity* affected);

    /**
      * Check to see if an entity has an event associated with the given verb.
      * @param verb the verb to check for.
      * @return true if the verb has an event, false otherwise.
      */
    bool hasEvent(std::string verb);

    /**
      * Checks to see if the entity could be a match for a given noun.
      * @param noun a word or phrase that could refer to the entity.
      * @return true if the entity matches with the noun, false otherwise.
      */
    bool matches(std::string noun);

    virtual void accept(Visitor& v);

  protected:
    EntitySpec* spec;  /**< Info for the entity. Owns this. */
    EntityState* state;  /**< Some states for the entity. Owns this */

    /**
      * The verbs that an entity has events for. Owns these.
      */
    std::map<std::string, Event*> events;

  private:
    Entity(const Entity&);
    Entity& operator=(const Entity&);
};

#endif // CALRISSIEN_2720_ENTITY_H
