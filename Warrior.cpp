//
// Created by Layer on 02/03/2018.
//

#include <cmath>
#include <algorithm>
#include <iostream>
#include "Warrior.h"
#include "Worker.h"
#include "Seed.h"

Warrior::Warrior(Map* m, Queen n, float x, float y) {
    this->map = m;
    this->nexus = n;
    this->x = x;
    this->y = y;

}

bool Warrior::attack(Warrior b) {
    //cout << "Warrior b :" << roundf(b.x) << roundf(b.y) << "Warrior a :" << roundf(this->x) << roundf(this->y) << endl;
    if(roundf(b.x) == roundf(this->x) && roundf(b.y) == roundf(this->y)){
        if(Seed::random(2) == 1){
            cout << "warrior fight" << endl;
            return (true);
        }
    } else{
        cout << "warrior move" << endl;
        nextPos(1, b.x, b.y);
    }
    return (false);
}

bool Warrior::think() {

    for(auto &i : map->entity){
        //cout << i << endl;
            if (typeid(*i) == typeid(Warrior)){
                vector<IEntity *> warrior = map->getEntity(typeid(Warrior));
                warrior = this->nearby(warrior);
                Warrior w = (Warrior&)*warrior[0];
                cout << typeid(w).name() << endl;
                if (this->nexus.side != w.nexus.side){
                    if (attack(w)){
                        cout << "BOOM" << endl;
                        for(int j = 0; j < map->entity.size() ; j++) {
                            /*if(map->entity[j] == w){
                                cout << "BOOM" << endl;
                            }*/

                        }
                    }
                }
            }
        }

   /* for(int i = 0; i < map->entity.size() ; i++){

        /*if (typeid(*i) == typeid(Queen)) {
            cout << "warrior" << endl;
            Queen n = (Queen &) *i;
            if (n.side != nexus.side) {
                if (n.x == round(x) && n.y == round(y)) {
                    if (n.health > 0) {
                        n.health -= 1;
                    } else {
                        map.entity.erase(map.entity.begin() + n.side);
                        return (false);
                    }
                } else {
                    nextPos(1, n.x, n.y);
                }
                return (true);
            }
        }*/

        //cout << map->entity.size() << endl;
        /*cout << typeid(map->entity[i]).name() << endl;
        if (typeid(map->entity[i]) == typeid(Water)) {
            cout << "IOUI" << endl;
        }
        if (typeid(map->entity[i]).name() == "Warrior") {
            cout << "NON" << endl;

            vector<Entity > warrior = map->getEntity(typeid(Warrior));
            warrior = this->nearby(warrior);
            Warrior n = (Warrior&)*warrior[0];

            if (this->nexus.side != n.nexus.side) {

                if (n.x == round(x) && n.y == round(y)) {
                    //cout << "IOUI" << endl;
                    //map.entity.erase(map.entity.begin() + n.nexus.side);
                    return (false);
                } else {
                    nextPos(1, n.x, n.y);
                    //cout << "je bouge" << endl;
                }
                return (true);
            }
        }*/


        /*if(typeid(*i) == typeid(Warrior)){
            cout << "warrior" << endl;
            vector<Entity*> warrior = map.getEntity(typeid(Warrior));
            warrior = this->nearby(warrior);
            Warrior w = (Warrior&)*warrior[0];
            if (attack(w)) {
                if (w.x == round(x) && w.y == round(y)) {

                } else {
                    nextPos(1, w.x, w.y);
                }
                return (true);
            }
            //Warrior w = (Warrior&)*i;
            if(w.nexus.side != nexus.side){
                if(attack(w)){
                    map.entity.erase(map.entity.begin() + w.nexus.side);
                    return (false);
                }
                return (true);
            }
        }


    }*/

        /*for(int i = 0; i < map.entity.size(); i++) {
            if (typeid(*map.entity[i]) == typeid(Warrior)) {
                cout << "warrior" << endl;
                vector<Entity > warrior = map.getEntity(typeid(Warrior));
                warrior = this->nearby(warrior);
                Warrior w = (Warrior &) *warrior[0];
                    if (attack(w)) {
                        if (w.x == round(x) && w.y == round(y)) {

                        } else {
                            nextPos(1, w.x, w.y);
                        }
                        return (true);
                    }
            }
        }
        /*for(auto &i : map.entity){
            if(typeid(*i) == typeid(Warrior)){
                cout << "warrior" << endl;
                vector<Entity*> warrior = map.getEntity(typeid(Warrior));
                warrior = this->nearby(warrior);
                Warrior w = (Warrior&)*warrior[0];
                if (attack(w)) {
                    if (w.x == round(x) && w.y == round(y)) {

                    } else {
                        nextPos(1, w.x, w.y);
                    }
                    return (true);
                }
                //Warrior w = (Warrior&)*i;
                if(w.nexus.side != nexus.side){
                    if(attack(w)){
                        map.entity.erase(map.entity.begin() + w.nexus.side);
                        return (false);
                    }
                    return (true);
                }
            }

            /*if(typeid(*i) == typeid(Queen)){
                Queen n = (Queen&)*i;
                if(n.side != nexus.side){
                    if(n.x == round(x) && n.y == round(y)){
                        if(n.health > 0){
                            n.health -= 1;
                        } else{
                            map.entity.erase(map.entity.begin() + n.side);
                            return (false);
                        }
                    } else{
                        nextPos(1, n.x, n.y);
                    }
                    return (true);
                }
            }

        }
        //nextPos(1, x + (Seed::random(20) - 10), y + (Seed::random(20) - 10));
        return (true);*/
    nextPos(1, x + (Seed::random(20) - 10), y + (Seed::random(20) - 10));
    return (true);
}

vector<IEntity *> Warrior::nearby(vector<IEntity *> cpEntity) {


    std::vector<double> v;
    vector<IEntity *> proEntity;

    for(int i = 0; i < cpEntity.size(); i++){

        if (typeid(*cpEntity[i]) == typeid(Warrior) && this->nexus.side != ((Warrior&)*cpEntity[i]).nexus.side) {
            v.push_back(this->range(this->x, this->y, ((Warrior&)*cpEntity[i]).x, ((Warrior&)*cpEntity[i]).y));
        }
        if (typeid(*cpEntity[i]) == typeid(Worker)) {
            v.push_back(this->range(this->x, this->y, ((Worker&)*cpEntity[i]).x, ((Worker&)*cpEntity[i]).y));
        }
        if (typeid(*cpEntity[i]) == typeid(Queen)) {
            v.push_back(this->range(this->x, this->y, ((Queen&)*cpEntity[i]).x, ((Queen&)*cpEntity[i]).y));
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
