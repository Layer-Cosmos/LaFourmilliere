//
// Created by Layer on 01/03/2018.
//

#ifndef LAFOURMILLIERE_ENTITY_H
#define LAFOURMILLIERE_ENTITY_H


#include "IEntity.h"

class Entity {
public:
    float x;
    float y;
    void nextPos(int speed, float ax, float ay);
    double range(float x, float y, float nX, float nY);
    bool think();
    void draw();
};


#endif //LAFOURMILLIERE_ENTITY_H
