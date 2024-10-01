#ifndef CONTINENT_H
#define CONTINENT_H
#include "Territory.h"

class Continent {
private:
    std::string name;
    std::vector<Territory> territories;

public:
    Continent();
    Continent(std::string name);
    std::string getName();
    std::vector<Territory> getTerritories();
    void setName(std::string name);
    void setTerritories(std::vector<Territory>);
};
#endif