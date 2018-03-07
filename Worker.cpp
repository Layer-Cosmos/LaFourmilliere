//
// Created by Layer on 08/03/2018.
//

#include "Worker.h"

Worker::Worker(Map m, Nexus n, float x, float y) {
    this->map = m;
    this->nexus = n;
    this->x = x;
    this->y = y;
}

bool Worker::think() {
    return false;
}
