#ifndef CALRISSIEN_2720_ENTITYSTATE_H
#define CALRISSIEN_2720_ENTITYSTATE_H


class EntityState
{
  public:
    EntityState();
    virtual ~EntityState();

    bool getObtainable();
    void setObtainable(bool);
    bool getActive();
    void setActive(bool);
    bool getHidden();
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
