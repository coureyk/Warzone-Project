#include "Territory.h"

//CONSTRUCTORS
Territory::Territory() {
    this->name = "";
    this->neighbors = std::vector<Territory>(); //initializing neighbors as empty vector
    armies = 0;
    this->isVisited = false;
}

Territory::Territory(std::string name) {
    this->name = name;
    this->neighbors = std::vector<Territory>(); //initializing neighbors as empty vector
    this->armies = 0;
    this->isVisited = false;
}

Territory::Territory(const Territory& other) {
    this->name = other.getName();
    this->neighbors = other.getNeighbors(); //shallow copy. To be corrected in A2.
    this->armies = other.getArmies();
    this->isVisited = other.getVisitedStatus();
}

//OVERLOADING OPERATOR=
Territory& Territory::operator=(const Territory& other) {
    //check for self-assignment
    if (this != &other) {
        this->name = other.getName();
        this->neighbors = other.getNeighbors();
        this->armies = other.getArmies();
        this->isVisited = other.getVisitedStatus();
    }
    return *this;
}

//USER-DEFINED FUNCTIONS
std::string Territory::getName() const {
    return this->name;
}

std::vector<Territory> Territory::getNeighbors() const {
    return this->neighbors;
}

int Territory::getArmies() const {
    return this->armies;
}

bool Territory::getVisitedStatus() const {
    return this->isVisited;
}

std::string Territory::summary() const {
    std::string neighbors = "";
    for (Territory t : this->neighbors) {
        neighbors.append((t.getName() + " "));
    }
    return this->name + "has the following the neighbors: " + neighbors + "\n\n";
}

void Territory::setName(std::string name) {
    this->name = name;
}

void Territory::setNeighbors(std::vector<Territory> neighbors) {
    this->neighbors = neighbors;
}

void Territory::setArmies(int armies) {
    this->armies = armies;
}

void Territory::setVisitedStatus(bool visitedStatus) {
    this->isVisited = visitedStatus;
}

//OVERLOADING OPERATOR<<
std::ostream& operator<<(std::ostream& os, const Territory& territory) {
    os << territory.summary();
    return os;
}
