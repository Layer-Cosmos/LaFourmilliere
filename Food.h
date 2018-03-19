//
// Created by Layer on 02/03/2018.
//

#ifndef LAFOURMILLIERE_FOOD_H
#define LAFOURMILLIERE_FOOD_H


#include "Entity.h"
#include "IEntity.h"

class Food: public Entity, public IEntity{
public:
    int stock;
    Food(float x, float y);
    bool think();

};


#endif //LAFOURMILLIERE_FOOD_H
