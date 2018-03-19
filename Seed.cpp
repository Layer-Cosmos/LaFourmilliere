//
// Created by Layer on 02/03/2018.
//

#include <cstdlib>
#include <ctime>
#include "Seed.h"

bool Seed::init = false;

int Seed::random(int i) {
    return (rand()%i);
}
int Seed::randomCord() {
    int rand = 0;
    int coord;
    rand = Seed::random(2);
    if(rand == 0){
        coord = -1;
    } else if (rand == 1){
        coord = 0;
    } else {
        coord = 1;
    }
    return (coord);
}

Seed::Seed() {
    if(!init){
        init = true;
        srand(time(0));
    }
}
