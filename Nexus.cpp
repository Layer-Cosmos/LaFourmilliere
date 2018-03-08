//
// Created by Layer on 07/03/2018.
//

#include "Nexus.h"
#include "Worker.h"
#include "Warrior.h"

Nexus::Nexus(Map* m, int s, float x, float y) {
    side = s;
    map = m;

    spawn = 200;
    food = 100;
    water = 100;
    health = 100;
    this->x = x;
    this->y = y;
}

Nexus::~Nexus() {

}

Nexus::Nexus() {

}

bool Nexus::think() {
    if (spawn > 100) {
        map->add(new Worker(*map, *this, this->x, this->y))
                .add(new Worker(*map, *this, this->x, this->y))
                .add(new Warrior(*map, *this, this->x, this->y));
        spawn = 0;
        return (false);
    } else {
        if (food > 0 && water > 0) {
            spawn += 1;
            water -= 1;
            food -= 1;
        }
    }
    return (true);
}
