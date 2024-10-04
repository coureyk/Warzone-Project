#include "Continent.h"

//CONSTRUCTORS
Continent::Continent() {

}

Continent::Continent(std::string name) {
    this->name = name;
    this->territories = std::vector<Territory>(); //initializing territories as empty vector
}

Continent::Continent(const Continent& other) {
    this->name = other.getName();
    this->territories = other.getTerritories(); //shallow copy. To be corrected in A2
}

//OVERLOADING OPERATOR=
Continent& Continent::operator=(const Continent& other) {
    //check for self-assignment
    if (this != &other) {
        this->name = other.getName();
        this->territories = other.getTerritories(); //shallow copy. To be corrected in A2
    }
    return *this;
}

//USER-DEFINED FUNCTIONS
std::string Continent::getName() const {
    return this->name;
}

std::vector<Territory> Continent::getTerritories() const {
    return this->territories;
}

std::string Continent::summary() const {
    std::string territories = "";
    for (Territory t : this->territories) {
        territories.append((t.getName() + " "));
    }
    return this->name + " contains the following territories: " + territories + "\n\n";
}

void Continent::setName(std::string name) {
    this->name = name;
}

void Continent::setTerritories(std::vector<Territory> contents) {
    this->territories = contents;
}

//OVERLOADING OPERATOR<<
std::ostream& operator<<(std::ostream& os, const Continent& continent) {
    os << continent.summary();
    return os;
}
