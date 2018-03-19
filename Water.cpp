//
// Created by Layer on 02/03/2018.
//

#include "Water.h"
#include "Seed.h"

Water::Water(float x, float y) {
    this->x = x;
    this->y = y;
    stock = 50 + Seed::random(200);
}

bool Water::think() {
    return true;
}
