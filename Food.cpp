//
// Created by Layer on 08/03/2018.
//

#include "Food.h"

Food::Food(float x, float y) {
    this->x = x;
    this->y = y;
    stock = 50;
}

bool Food::think() {
    return false;
}
