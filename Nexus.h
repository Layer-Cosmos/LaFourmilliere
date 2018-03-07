//
// Created by Layer on 07/03/2018.
//

#ifndef LAFOURMILLIERE_NEXUS_H
#define LAFOURMILLIERE_NEXUS_H


#include "Map.h"
#include "Entity.h"

class Nexus: public Entity{
public:
    int side;
    int food;
    int water;
    int health;
    float nX;
    float nY;
    bool think();
    Nexus();
    Nexus(Map*, int, float, float);
    ~Nexus();
private:
    int spawn;
    Map* map;
protected:


};


#endif //LAFOURMILLIERE_NEXUS_H
