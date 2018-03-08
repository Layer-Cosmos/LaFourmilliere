//
// Created by Layer on 08/03/2018.
//

#ifndef LAFOURMILLIERE_WARRIOR_H
#define LAFOURMILLIERE_WARRIOR_H


#include "Entity.h"
#include "Nexus.h"

class Warrior: public Entity, public IEntity {
public:
    Nexus nexus;
    Warrior(Map m, Nexus n , float x, float y);
    bool think();

private:
    Map map;
    bool attack(Entity b);

};


#endif //LAFOURMILLIERE_WARRIOR_H
