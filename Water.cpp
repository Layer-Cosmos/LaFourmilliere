//
// Created by Layer on 08/03/2018.
//

#include "Water.h"

Water::Water(float x, float y) {
    this->x = x;
    this->y = y;
    stock = 50;
}

bool Water::think() {
    return false;
}
