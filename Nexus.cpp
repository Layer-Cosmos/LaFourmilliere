//
// Created by Layer on 07/03/2018.
//

#include "Nexus.h"

Nexus::Nexus(Map* m, int s, float x, float y) {
    side = s;
    map = m;

    spawn = 200;
    food = 100;
    water = 100;
    health = 100;
    nX = x;
    nY = y;
}

Nexus::~Nexus() {

}

Nexus::Nexus() {
    nX = 0;
    nY = 0;
}

bool Nexus::think() {
    return false;
}
