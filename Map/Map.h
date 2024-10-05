#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stdexcept>

class Continent; // Forward declaration
class Territory; // Forward declaration
class Map {
private:
    std::vector<Territory*> territories;
    std::vector<Continent*> continents;

public:
    Map();
    Map(const Map& other); // Copy constructor
    Map& operator=(const Map& other); // Assignment operator
    ~Map(); // Destructor

    void addTerritory(Territory* territory);
    void addContinent(Continent* continent);
    std::vector<Continent*> getContinents() const; // Getter for continents
    std::vector<Territory*> getTerritories() const; // Getter for territories

    bool validate() const; // Validation method

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Map& map);
};


class Territory {
private:
    std::string name;
    Continent* continent;
    std::string owner;
    int armies;
    std::vector<Territory*> adjacentTerritories;

public:
    Territory(std::string name, Continent* continent, std::string owner, int armies);
    Territory(const Territory& other); // Copy constructor
    Territory& operator=(const Territory& other); // Assignment operator
    ~Territory(); // Destructor

    void addAdjacentTerritory(Territory* territory);
    std::string getName() const;
    Continent* getContinent() const;
    std::vector<Territory*> getAdjacentTerritories() const;

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Territory& territory);
};

class Continent {
private:
    std::string name;
    std::vector<Territory*> territories;

public:
    Continent(std::string name);
    Continent(const Continent& other); // Copy constructor
    Continent& operator=(const Continent& other); // Assignment operator
    ~Continent(); // Destructor

    void addTerritory(Territory* territory);
    std::string getName() const;
    std::vector<Territory*> getTerritories() const;

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Continent& continent);
};

class MapLoader {
private:
    std::string filePath;

public:
    MapLoader(std::string filePath);
    Map* loadMap(); // Loads a map from a file

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const MapLoader& mapLoader);
};

#endif // TERRITORY_H
