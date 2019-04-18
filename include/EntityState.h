/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-05
 */

#ifndef CALRISSIEN_2720_ENTITYSTATE_H
#define CALRISSIEN_2720_ENTITYSTATE_H

/**
  * Holds the state of an entity
  */
class EntityState {
 public:
  EntityState();
  EntityState(bool active, bool obtainable, bool hidden);
  virtual ~EntityState();

  /**
    * @return obtainable
    */
  bool getObtainable() const;

  /**
    * Change obtainable
    * @param ob the new value of obtainable
    */
  void setObtainable(bool ob);

  /**
    * @return active
    */
  bool getActive() const;

  /**
    * Change active
    * @param a the new value of active
    */
  void setActive(bool a);

  /**
    * @return hidden
    */
  bool getHidden() const;

  /**
    * Change hidden
    * @param the new value of hidden
    */
  void setHidden(bool);

 private:
  bool obtainable;
  bool active;
  bool hidden;

  EntityState(const EntityState&);
  EntityState& operator=(const EntityState&);
};

#endif // ENTITYSTATE_H
