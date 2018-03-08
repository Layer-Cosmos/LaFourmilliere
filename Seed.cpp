//
// Created by Layer on 08/03/2018.
//

#include <cstdlib>
#include <ctime>
#include "Seed.h"

bool Seed::init = false;

int Seed::random(int i) {
    return (rand()%i);
}

Seed::Seed() {
    if(!init){
        init = true;
        srand(time(0));
    }
}
