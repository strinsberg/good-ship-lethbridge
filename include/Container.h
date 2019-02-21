#ifndef CALRISSIEN_2720_CONTAINER_H
#define CALRISSIEN_2720_CONTAINER_H

#include "Entity.h"
#include <map>

class Container: public Entity
{
  public:
    Container();
    virtual ~Container();
    virtual void describe();
    virtual void use(Entity&) = 0;
    virtual void serialize(fstream&) = 0;

    Entity& search(string);
    void addEntity(Entity*);
    Entity* removeEntity(Entity&);

  protected:
    map<string, Entity*> inventory;

  private:
    Container(const Container&);
    Container& operator=(const Container&);
};

#endif // CONTAINER_H
