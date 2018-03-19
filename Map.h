//
// Created by Layer on 01/03/2018.
//

#ifndef LAFOURMILLIERE_MAP_H
#define LAFOURMILLIERE_MAP_H


#include "Entity.h"
#include "IEntity.h"
#include <list>
#include <vector>
#include <typeinfo>

using namespace std;

class Map {

public:
    static Map* getInstance();
    void startup();
    bool draw();
    vector<IEntity*> entity;
    static Map* _instance;
    Map add(IEntity* e);
    vector<IEntity *> getEntity(const type_info & entity);
    bool think();

protected:

    int frame;
    int size = 64;


};


#endif //LAFOURMILLIERE_MAP_H
