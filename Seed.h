//
// Created by Layer on 02/03/2018.
//

#ifndef LAFOURMILLIERE_SEED_H
#define LAFOURMILLIERE_SEED_H

#include <cstdlib>
#include <ctime>


class Seed {
public:
    Seed();
    static int random(int i);
    static int randomCord();
    static bool init;

};


#endif //LAFOURMILLIERE_SEED_H
