#include <iostream>
#include <zconf.h>
#include "Map.h"
#include "Seed.h"

int main() {
    Map *map = Map::getInstance();
    Seed seed = Seed();
    bool run = true;
    map->startup();
    while (run){
        map->think();
        map->draw();
        //std::cout << "Reset" << std::endl;
        sleep(1);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}