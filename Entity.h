//
// Created by Layer on 07/03/2018.
//

#ifndef LAFOURMILLIERE_ENTITY_H
#define LAFOURMILLIERE_ENTITY_H


class Entity {
public:
    float x;
    float y;
    void nextPos(int speed, float ax, float ay);
    virtual bool think() = 0;
    void draw();
};


#endif //LAFOURMILLIERE_ENTITY_H
