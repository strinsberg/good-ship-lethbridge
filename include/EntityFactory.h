#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"
#include "Container.h"
#include "Player.h"
#include "json.h"

using json = nlohmann::json;

class EntityFactory
{
    public:
        EntityFactory();
        virtual ~EntityFactory();

        Entity* makeEntity(const json& obj);
        Container* makeContainer(const json& obj);
        Player* makePlayer(const json& obj);

    private:
        void setupEntity(Entity* e, const json& obj);

        EntityFactory(const EntityFactory& other);
        EntityFactory& operator=(const EntityFactory& other);
};

#endif // ENTITYFACTORY_H
