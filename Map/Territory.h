#ifndef TERRITORY_H
#define TERRITORY_H
#include <vector>
#include <string>

class Territory {
private:
    std::string name;
    std::vector<Territory> neighbors;
    int armies;

public:
    Territory();
    Territory(std::string name);
    std::string getName();
    std::vector<Territory> getNeighbors();
    int getArmies();
    void setName(std::string name);
    void setNeighbors(std::vector<Territory> neighbors);
    void setArmies(int armies);
    bool operator==(Territory& otherTerritory);
};
#endif