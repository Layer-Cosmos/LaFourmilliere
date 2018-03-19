//
// Created by layer on 18/03/18.
//

#ifndef LAFOURMILLIERE_IENTITY_H
#define LAFOURMILLIERE_IENTITY_H


class IEntity {
public:
    void draw();
    virtual bool think() = 0;

};


#endif //LAFOURMILLIERE_IENTITY_H
