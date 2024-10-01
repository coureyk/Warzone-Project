#include "Continent.h"

Continent::Continent() {

}

Continent::Continent(std::string name) {
    this->name = name;
}

std::string Continent::getName() {
    return this->name;
}

std::vector<Territory> Continent::getTerritories() {
    return this->territories;
}

void Continent::setName(std::string name) {
    this->name = name;
}

void Continent::setTerritories(std::vector<Territory> contents) {
    this->territories = contents;
}
