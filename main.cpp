#include <iostream>
#include "Map.h"

int main() {
    Map *map = Map::getInstance();
    map->startup();
    map->draw();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}