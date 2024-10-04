#ifndef TERRITORY_H
#define TERRITORY_H
#include <vector>
#include <string>
#include <iostream>

class Territory {
private:
    std::string name;
    std::vector<Territory> neighbors;
    int armies;

public:
    //Constructors
    Territory();
    Territory(std::string name);
    Territory(const Territory& other);

    //Overloading operator=
    Territory& operator=(const Territory& other);

    //User-defined functions
    std::string getName() const;
    std::vector<Territory> getNeighbors() const;
    int getArmies() const;
    std::string summary() const;
    void setName(std::string name);
    void setNeighbors(std::vector<Territory> neighbors);
    void setArmies(int armies);
};

//Overloading operator<<
std::ostream& operator<<(std::ostream& os, const Territory& territory);

#endif