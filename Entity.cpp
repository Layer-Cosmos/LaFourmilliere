//
// Created by Layer on 01/03/2018.
//

#include <cmath>
#include <algorithm>
#include "Entity.h"
using namespace std;

void Entity::nextPos(int speed, float ax, float ay) {
    double angle = atan2(ay - y, ax - x);
    this->x = (float)max(0.0, min(63.0, x + (speed * cos(angle))));
    this->y = (float)max(0.0, min(63.0, y + (speed * sin(angle))));
}

bool Entity::think() {
    return (true);
}

double Entity::range(float x, float y, float nX, float nY) {
    return sqrt((x-nX)*(x-nX)+(y-nY)*(y-nY));
}
