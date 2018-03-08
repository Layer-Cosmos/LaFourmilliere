//
// Created by Layer on 07/03/2018.
//

#ifndef LAFOURMILLIERE_NEXUS_H
#define LAFOURMILLIERE_NEXUS_H


#include "Map.h"
#include "Entity.h"
#include "IEntity.h"

class Nexus: public Entity, public IEntity {
public:
    int side;
    int food;
    int water;
    int health;
    bool think();
    Nexus();
    Nexus(Map* m, int s, float x, float y);
    ~Nexus();
private:
    int spawn;
    Map* map;
protected:


};


#endif //LAFOURMILLIERE_NEXUS_H
