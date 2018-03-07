//
// Created by Layer on 07/03/2018.
//

#ifndef LAFOURMILLIERE_MAP_H
#define LAFOURMILLIERE_MAP_H


#include "Entity.h"
#include <list>
#include <vector>

using namespace std;

class Map {

public:
    static Map* getInstance();
    void startup();
    bool draw();
    vector<Entity*> entity;
    static Map* _instance;

protected:

    int frame;
    int size = 64;


};


#endif //LAFOURMILLIERE_MAP_H
