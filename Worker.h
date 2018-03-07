//
// Created by Layer on 08/03/2018.
//

#ifndef LAFOURMILLIERE_WORKER_H
#define LAFOURMILLIERE_WORKER_H


#include "Entity.h"
#include "Nexus.h"

class Worker: public Entity {
public:
    int age;
    Nexus nexus;
    Worker(Map m, Nexus n, float x, float y);
    bool think();
private:
    Map map;
};


#endif //LAFOURMILLIERE_WORKER_H
