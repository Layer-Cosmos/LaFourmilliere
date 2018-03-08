//
// Created by Layer on 07/03/2018.
//

#include <cmath>
#include "Entity.h"
using namespace std;

void Entity::nextPos(int speed, float ax, float ay) {
    double angle = atan2(ay - y, ax - x);
    x = (float)max(0.0, min(63.0, x + (speed * cos(angle))));
    y = (float)max(0.0, min(63.0, y + (speed * sin(angle))));
}

bool Entity::think() {
    return (true);
}