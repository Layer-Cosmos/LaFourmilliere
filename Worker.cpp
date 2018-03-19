//
// Created by Layer on 02/03/2018.
//

#include <cmath>
#include "Worker.h"
#include "Food.h"
#include "Water.h"
#include "Seed.h"
#include <typeinfo>
#include <iostream>
#include <vector>
#include <algorithm>

Worker::Worker(Map* m, Queen n, float x, float y) {
    this->map = m;
    this->nexus = n;
    this->x = x;
    this->y = y;
    this->food = 0;
    this->water = 0;
}

bool Worker::think() {
    nexus.health = min(100, nexus.health + 1);

    for(auto &i : map->entity){
        if (typeid(*i) == typeid(Water)) {
            vector<IEntity *> water = map->getEntity(typeid(Water));
            water = this->nearby(water);
            Water w = (Water&)*water[0];
            if(this->nexus.water < this->nexus.food) {
                cout << "IOUI" << endl;
                if (this->water > 0) {
                    if (this->nexus.x == round(x) && this->nexus.y == round(y)) {
                        nexus.water += 10;
                        this->water = 0;
                    } else {
                        nextPos(1, this->nexus.x, this->nexus.y);
                    }
                    return (true);
                }
                if (w.stock > 0) {
                    if (w.x == round(x) && w.y == round(y)) {
                        w.stock -= 10;
                        this->water = 10;
                    } else {
                        nextPos(1, w.x, w.y);
                    }
                    return (true);
                }
            }
        }
        if (typeid(*i) == typeid(Food)) {
            vector<IEntity*> food = map->getEntity(typeid(Food));
            food = this->nearby(food);
            Food f = (Food&)*food[0];
            if (this->food > 0){
                if (this->nexus.x == round(x) && this->nexus.y == round(y)) {
                    nexus.food += 10;
                    this->food = 0;
                } else {
                    nextPos(1, this->nexus.x, this->nexus.y);
                }
                return (true);
            }
            if (f.stock > 0) {
                if (f.x == round(x) && f.y == round(y)) {
                    f.stock -= 10;
                    this->food = 10;
                } else {
                    nextPos(1, f.x, f.y);
                }
                return (true);
            }
        }

    /*for(int i = 0; i < map->entity.size(); i++){
        //cout << "IOUI" << endl;
        if(typeid(map->entity[i]) == typeid(Water)){
            cout << "IOUI" << endl;

            vector<IEntity *> water = map->getEntity(typeid(Water));
            water = this->nearby(water);
            Water w = (Water&)*water[0];
            if(this->nexus.water < this->nexus.food) {
                if (this->water > 0) {
                    if (this->nexus.x == round(x) && this->nexus.y == round(y)) {
                        nexus.water += 10;
                        this->water = 0;
                    } else {
                        nextPos(1, this->nexus.x, this->nexus.y);
                    }
                    return (true);
                }
                if (w.stock > 0) {
                    if (w.x == round(x) && w.y == round(y)) {
                        w.stock -= 10;
                        this->water = 10;
                    } else {
                        nextPos(1, w.x, w.y);
                    }
                    return (true);
                }
            }
        }

        /*if(typeid(*map.entity[i]) == typeid(Food)){
            vector<Entity*> food = map.getEntity(typeid(Food));
            food = this->nearby(food);
            Food f = (Food&)*food[0];
            if (this->food > 0){
                if (this->nexus.x == round(x) && this->nexus.y == round(y)) {
                    nexus.food += 10;
                    this->food = 0;
                } else {
                    nextPos(1, this->nexus.x, this->nexus.y);
                }
                return (true);
            }
            if (f.stock > 0) {
                if (f.x == round(x) && f.y == round(y)) {
                    f.stock -= 10;
                    this->food = 10;
                } else {
                    nextPos(1, f.x, f.y);
                }
                return (true);
            }
        }
    }
    /*for(auto &i : map.entity) {
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
            std::cout << typeid(Water).name() << endl;
            map.getEntity(typeid(Water));
            Water w = (Water&)*i;
            if (this->water > 0){
                if (this->nexus.x == round(x) && this->nexus.y == round(y)) {
                    nexus.water += 1;
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
        }*/
    }
    nextPos(1, x + (Seed::random(20) - 10), y + (Seed::random(20) - 10));
    return (true);
}

vector<IEntity *> Worker::nearby(vector<IEntity *> cpEntity) {
    std::vector<double> v;
    vector<IEntity *> proEntity;

    for(int i = 0; i < cpEntity.size(); i++){

        if (typeid(*cpEntity[i]) == typeid(Food)) {
            v.push_back(range(this->x, this->y, ((Food&)*cpEntity[i]).x, ((Food&)*cpEntity[i]).y));
        }
        if (typeid(*cpEntity[i]) == typeid(Water)) {
            v.push_back(range(this->x, this->y, ((Water&)*cpEntity[i]).x, ((Water&)*cpEntity[i]).y));
        }


        //cout << this->range(this->x, this->y, ((Water&)*cpEntity[i]).x, ((Water&)*cpEntity[i]).y) << endl;
        //cout << this->range(this->range(this->x, this->y, ((Water&)*cpEntity[i]).x, ((Water&)*cpEntity[i]).y)) << endl;
    }
    std::vector<double>::iterator result = std::min_element(std::begin(v), std::end(v));
    //cout << std::distance(std::begin(v), result) << endl;
    int it = std::distance(std::begin(v), result);
    //cout << it << endl;
    proEntity.push_back(cpEntity[it]);

    return (proEntity);
}
