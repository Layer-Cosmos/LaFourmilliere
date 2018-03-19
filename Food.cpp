//
// Created by Layer on 02/03/2018.
//

#include "Food.h"
#include "Seed.h"

Food::Food(float x, float y) {
    this->x = x;
    this->y = y;
    stock = 50 + Seed::random(200);
}

bool Food::think() {
    return (true);
}
