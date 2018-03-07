//
// Created by Layer on 08/03/2018.
//

#ifndef LAFOURMILLIERE_FOOD_H
#define LAFOURMILLIERE_FOOD_H


#include "Entity.h"

class Food: public Entity {
public:
    int stock;
    Food(float x, float y);
    bool think();

};


#endif //LAFOURMILLIERE_FOOD_H
