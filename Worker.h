//
// Created by Layer on 02/03/2018.
//

#ifndef LAFOURMILLIERE_WORKER_H
#define LAFOURMILLIERE_WORKER_H


#include "IEntity.h"
#include "Queen.h"
#include "Entity.h"
#include "Water.h"

class Worker: public Entity, public IEntity{
public:
    int side;
    int water;
    int food;
    Queen nexus;
    Worker(Map* m, Queen n, float x, float y);
    std::vector<IEntity *> nearby(std::vector<IEntity *> cpEntity);
    bool think();
private:
    Map* map;
};


#endif //LAFOURMILLIERE_WORKER_H
