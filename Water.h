//
// Created by Layer on 08/03/2018.
//

#ifndef LAFOURMILLIERE_WATER_H
#define LAFOURMILLIERE_WATER_H


#include "Entity.h"

class Water: public Entity {
public:
    int stock;
    bool think();
    Water(float x, float y);

};


#endif //LAFOURMILLIERE_WATER_H
