#include "Map.h"
#include <iostream>

void testLoadMaps() {
    Map* map = new Map();
    
    Territory* t1 = new Territory("Siam");
    Territory* t2 = new Territory("Japan");
    Territory* t3 = new Territory("Ural");
    Territory* t4 = new Territory("Asia");
    Territory* t5 = new Territory("China");
    Territory* t6 = new Territory("India");
    Territory* t7 = new Territory("Indonesia");
    Territory* t8 = new Territory("Kamchatka");
    Territory* t9 = new Territory("Mongolia");
    Territory* t10 = new Territory("Siberia");
    Territory* t11 = new Territory("Afghanistan");
    Territory* t12 = new Territory("Ukraine");

    std::vector<Territory> n1 = { *t4, *t5, *t6, *t7 };
    t1->setNeighbors(n1);

    std::vector<Territory> n2 = { *t4, *t8, *t9 };
    t2->setNeighbors(n2);

    std::vector<Territory> n3 = { *t4, *t10, *t5, *t11, *t12 };
    t3->setNeighbors(n3);

    Continent* c1 = new Continent("America");
    Continent* c2 = new Continent("Africa");
    Continent* c3 = new Continent("Europe");

    std::vector<Territory> v1 = { *t1, *t2, *t3, *t4 };
    std::vector<Territory> v2 = { *t5, *t6, *t7, *t8 };
    std::vector<Territory> v3 = { *t9, *t10, *t11, *t12 };

    c1->setTerritories(v1);
    c2->setTerritories(v2);
    c3->setTerritories(v3);

    std::vector<Continent> v4 = { *c1,*c2, *c3 };

    map->setContinents(v4);

    for (int i = 0; i < map->getContinents().size(); i++) {
        std::cout << "Continent: " << map->getContinents().at(i).getName() << "\n";
        std::cout << "Members: ";
        for (int j = 0; j < map->getContinents().at(i).getTerritories().size(); j++) {
            std::cout << map->getContinents().at(i).getTerritories().at(j).getName() << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    for (int i = 0; i < map->getContinents().size(); i++) {
        std::cout << "Continent: " << map->getContinents().at(i).getName() << "\n";
        for (int j = 0; j < map->getContinents().at(i).getTerritories().size(); j++) {
            std::cout << "Territory: " << map->getContinents().at(i).getTerritories().at(j).getName() << "\n";
            std::cout << "Neighbors: ";
            for (int k = 0; k < map->getContinents().at(i).getTerritories().at(j).getNeighbors().size(); k++) {
                std::cout << map->getContinents().at(i).getTerritories().at(j).getNeighbors().at(k).getName() << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

void testLoadMaps2() {
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