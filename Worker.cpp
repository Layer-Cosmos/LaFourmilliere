//
// Created by Layer on 08/03/2018.
//

#include <cmath>
#include "Worker.h"
#include "Food.h"
#include "Water.h"
#include "Seed.h"

Worker::Worker(Map m, Nexus n, float x, float y) {
    this->map = m;
    this->nexus = n;
    this->x = x;
    this->y = y;
    this->food = 0;
    this->water = 0;
}

bool Worker::think() {
    nexus.health = min(100, nexus.health + 1);

    for(auto &i : map.entity) {
        if(typeid(*i) == typeid(Food)){
            Food f = (Food&)*i;
            if (f.stock > 0) {
                if (f.x == round(x) && f.y == round(y)) {
                    f.stock -= 1;
                    this->food = 1;
                } else {
                    nextPos(1, f.x, f.y);
                }
                return (true);
            }
        }

        if(typeid(*i) == typeid(Water)){
            Water w = (Water&)*i;
            if (this->water > 0){
                if (this->nexus.x == round(x) && this->nexus.y == round(y)) {
                    nexus.water *= 1;
                    this->water = 0;
                } else {
                    nextPos(1, this->nexus.x, this->nexus.y);
                }
                return (true);
            }
            if (w.stock > 0) {
                if (w.x == round(x) && w.y == round(y)) {
                    w.stock -= 1;
                    this->water = 1;
                } else {
                    nextPos(1, w.x, w.y);
                }
                return (true);
            }
        }
    }
    nextPos(1, x + (Seed::random(20) - 10), y + (Seed::random(20) - 10));
    return (true);
}
