#ifndef CALRISSIEN_2720_ENTITYSTATE_H
#define CALRISSIEN_2720_ENTITYSTATE_H


/**
  * Holds the state of an entity
  */
class EntityState
{
  public:
    EntityState();
    virtual ~EntityState();

    /**
      * @return obtainable
      */
    bool getObtainable();

    /**
      * Change obtainable
      * @param ob the new value of obtainable
      */
    void setObtainable(bool ob);

    /**
      * @return active
      */
    bool getActive();

    /**
      * Change active
      * @param a the new value of active
      */
    void setActive(bool a);

    /**
      * @return hidden
      */
    bool getHidden();

    /**
      * Change hidden
      * @param the new value of hidden
      */
    void setHidden(bool);

  protected:

  private:
    bool obtainable;
    bool active;
    bool hidden;

    EntityState(const EntityState&);
    EntityState& operator=(const EntityState&);
};

#endif // ENTITYSTATE_H
