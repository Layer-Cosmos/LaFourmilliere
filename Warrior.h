//
// Created by Layer on 02/03/2018.
//

#ifndef LAFOURMILLIERE_WARRIOR_H
#define LAFOURMILLIERE_WARRIOR_H

#include "IEntity.h"
#include "Entity.h"
#include "Queen.h"

class Warrior: public Entity, public IEntity{
public:
    Queen nexus;
    Warrior(Map* m, Queen n , float x, float y);
    vector<IEntity *> nearby(vector<IEntity *> cpEntity);
    bool think();

private:
    Map* map;
    bool attack(Entity b);

    bool attack(Warrior b);
};


#endif //LAFOURMILLIERE_WARRIOR_H
