#include "Map.h"

std::vector<Continent> Map::continents{};

Map::Map(std::vector<Continent> continents) {
    Map::continents = continents;
}

std::vector<Continent> Map::getContinents() {
    return Map::continents;
}

void Map::setContinents(std::vector<Continent> continents) {
    Map::continents = continents;
}

bool Map::validate() {
    return true;
}