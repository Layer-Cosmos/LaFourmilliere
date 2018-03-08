//
// Created by Layer on 08/03/2018.
//

#ifndef LAFOURMILLIERE_WORKER_H
#define LAFOURMILLIERE_WORKER_H


#include "Entity.h"
#include "Nexus.h"
#include "IEntity.h"

class Worker: public Entity, public IEntity {
public:
    int age;
    int water;
    int food;
    int salue;
    Nexus nexus;
    Worker(Map m, Nexus n, float x, float y);
    bool think();
private:
    Map map;
};


#endif //LAFOURMILLIERE_WORKER_H
