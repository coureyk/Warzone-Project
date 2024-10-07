#include "Territory.h"

Territory::Territory() {
    armies = 0;
}

Territory::Territory(std::string name) {
    this->name = name;
    this->armies = 0;
}

std::string Territory::getName() {
    return this->name;
}

std::vector<Territory> Territory::getNeighbors() {
    return this->neighbors;
}

int Territory::getArmies() {
    return this->armies;
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

bool Territory::operator==(Territory& otherTerritory) {
    if (name == otherTerritory.getName())
        return true;
    else
        return false;
}