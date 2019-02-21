#ifndef CALRISSIEN_2720_CONTAINER_H
#define CALRISSIEN_2720_CONTAINER_H

#include "Entity.h"
#include <map>


class Container: public Entity
{
  public:
    Container();
    virtual ~Container();
    void describe();
    void use(Entity&);
    void serialize(fstream&);

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
