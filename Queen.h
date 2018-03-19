//
// Created by Layer on 01/03/2018.
//

#ifndef LAFOURMILLIERE_NEXUS_H
#define LAFOURMILLIERE_NEXUS_H


#include "Map.h"
#include "Entity.h"
#include "Entity.h"

class Queen: public Entity, public IEntity{
public:
    int side;
    int food;
    int water;
    int health;
    bool think();
    Queen();
    Queen(Map* m, int s, float x, float y);
    ~Queen();
private:
    int spawn;
    Map* map;
protected:


};


#endif //LAFOURMILLIERE_NEXUS_H
