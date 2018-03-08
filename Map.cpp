//
// Created by Layer on 07/03/2018.
//

#include "Map.h"
#include "Nexus.h"
#include "Water.h"
#include "Food.h"
#include "Seed.h"
#include "Worker.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <cmath>



using namespace std;

Map* Map::_instance = NULL;

Map* Map::getInstance() {
    if(_instance == 0){
        _instance = new Map();
    }
    return (_instance);
}

void Map::startup() {
    size = 64;
    frame = 5000;
    entity.push_back(new Nexus(this->_instance, 1, Seed::random(size), Seed::random(size)));
    entity.push_back(new Nexus(this->_instance, 2, Seed::random(size), Seed::random(size)));
    entity.push_back(new Water(Seed::random(size), Seed::random(size)));
    entity.push_back(new Water(Seed::random(size), Seed::random(size)));
    entity.push_back(new Food(Seed::random(size), Seed::random(size)));
    entity.push_back(new Food(Seed::random(size), Seed::random(size)));
}

bool Map::draw(){
    string base = "";

    for (int i = 0; i < size; i++){
        for (int k = 0; k < size; k++){
            base += ".";
        }
        base += '\n';
    }

    int s = size + 1;

    for(auto &i : entity){
        if(typeid(*i) == typeid(Nexus)){

            Nexus n = (Nexus&)*i;

            base.replace((round(n.y) * s) + round(n.x), 1, "n");
        }
        if(typeid(*i) == typeid(Water)){

            Water w = (Water&)*i;

            base.replace((round(w.y) * s) + round(w.x), 1, "w");
        }
        if(typeid(*i) == typeid(Food)){

            Food f = (Food&)*i;

            base.replace((round(f.y) * s) + round(f.x), 1, "f");
        }
        if(typeid(*i) == typeid(Worker)){

            Worker a = (Worker&)*i;

            base.replace((round(a.y) * s) + round(a.x), 1, "a");
        }
        if(typeid(*i) == typeid(Warrior)){

            Warrior x = (Warrior&)*i;

            base.replace((round(x.y) * s) + round(x.x), 1, "x");
        }
    }

    cout << base << endl;
}

Map Map::add(IEntity *e) {
    entity.push_back(e);
    return (*this);
}

bool Map::think() {
    for(auto &i : entity) {
        if (typeid(*i) == typeid(Nexus)) {
            if(!((Nexus&)*i).think()){
                return (true);
            }
        }
        if (typeid(*i) == typeid(Water)) {
            ((Water&)*i).think();
        }
        if (typeid(*i) == typeid(Worker)) {
            if (!((Worker&)*i).think()) {
                return (true);
            }
        }
    }
    return false;
}

