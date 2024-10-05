#ifndef MAP_H
#define MAP_H
#include "Continent.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <stdexcept>

class Map {
private:
    static std::vector<Continent> continents;

public:
    //Constructors
    Map();
    Map(std::vector<Continent> continents);
    Map(const Map& other);

    //Overload operator=
    Map& operator=(const Map& other);

    //User-defined functions
    std::vector<Continent> getContinents() const;
    void setContinents(std::vector<Continent>);
    bool validate() const;
};

//Overload oeprator<<
std::ostream& operator<<(std::ostream& os, const Map& map);
#endif

class MapLoader {
private:
    std::string filePath;

public: 
    MapLoader(std::string filePath);
    Map* loadMap(); // Loads a map from a file

    std::string getFilePath() const;
};

//Overload operator<<
std::ostream& operator<<(std::ostream& os, const MapLoader& mapLoader);
