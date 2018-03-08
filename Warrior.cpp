//
// Created by Layer on 08/03/2018.
//

#include <cmath>
#include "Warrior.h"

Warrior::Warrior(Map m, Nexus n, float x, float y) {
    this->map = m;
    this->nexus = n;
    this->x = x;
    this->y = y;

}

bool Warrior::attack(Entity b) {
    if(b.x == round(x) && b.y == round(y)){
        if(1){
            return (true);
        } else{
            nextPos(1, b.x, b.y);
        }
        return (false);
    }
}

bool Warrior::think() {
    return false;
}
