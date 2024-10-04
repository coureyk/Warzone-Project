#ifndef CONTINENT_H
#define CONTINENT_H
#include "Territory.h"
#include <iostream>

class Continent {
private:
    std::string name;
    std::vector<Territory> territories;

public:
    //Constructors
    Continent();
    Continent(std::string name);
    Continent(const Continent& other);

    Continent& operator=(const Continent& other);

    //User-defined Functions
    std::string getName() const;
    std::vector<Territory> getTerritories() const;
    std::string summary() const;
    void setName(std::string name);
    void setTerritories(std::vector<Territory>);
};

//Overloading operator<<
std::ostream& operator<<(std::ostream& os, const Continent& continent);
#endif