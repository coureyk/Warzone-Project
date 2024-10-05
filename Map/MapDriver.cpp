#include "Map.h"
#include <iostream>

void testLoadMaps() {
    MapLoader loader("USA.map");
    Map* map = loader.loadMap();

    if (map->validate()) {
        std::cout << "Map is valid!" << std::endl;
    }
    else {
        std::cout << "Map is invalid!" << std::endl;
    }

    delete map;
}