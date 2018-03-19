//
// Created by Layer on 01/03/2018.
//

#include <iostream>
#include "Queen.h"
#include "Worker.h"
#include "Seed.h"
#include "Warrior.h"

Queen::Queen(Map* m, int s, float x, float y) {
    side = s;
    map = m;

    spawn = 0;
    food = 100;
    water = 100;
    health = 100;
    this->x = x;
    this->y = y;
    map->entity.push_back(new Warrior(map, *this, this->x, this->y));
    map->entity.push_back(new Worker(map, *this, this->x + Seed::randomCord(), this->y + Seed::randomCord()));
}

Queen::~Queen() {

}

Queen::Queen() {

}

bool Queen::think() {
    if (spawn > 50) {
        /*map->add(new Warrior(*map, *this, this->x, this->y));
        map->add(new Worker(*map, *this, this->x + Seed::randomCord(), this->y + Seed::randomCord()));
        map->add(new Worker(*map, *this, this->x + Seed::randomCord(), this->y + Seed::randomCord()));*/
        //map->entity.push_back(new Warrior(map, *this, this->x, this->y));

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
