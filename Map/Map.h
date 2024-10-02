#ifndef MAP_H
#define MAP_H
#include "Continent.h"

class Map {
private:
    static std::vector<Continent> continents;

public:
    Map(std::vector<Continent> continents);
    static std::vector<Continent> getContinents();
    static void setContinents(std::vector<Continent>);
    static bool validate();
};
#endif