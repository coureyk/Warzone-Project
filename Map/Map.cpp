#include "Map.h"

//DEFINING CLASS MEMBERS FOR MAP

std::vector<Continent> Map::continents{};

//CONSTRUCTORS 
Map::Map() {
    
}

Map::Map(std::vector<Continent> continents) {
    Map::continents = continents;
}

Map::Map(const Map& other) {
    this->continents = other.getContinents();
}

//OVERLOAD OPERATOR=
Map& Map::operator=(const Map& other) {
    if (this != &other) { // Self-assignment check
        this->continents = other.getContinents();
    }
    return *this;
}

//USER-DEFINED FUNCTIONS
std::vector<Continent> Map::getContinents() const {
    return Map::continents;
}

void Map::setContinents(std::vector<Continent> continents) {
    Map::continents = continents;
}

bool Map::validate() const {
    // Perform a BFS to check if the map is a connected graph
    std::vector<Territory> territories;

    for (Continent c : continents) {
        for (Territory t : c.getTerritories()) {
            for (Territory neighbor : t.getNeighbors()) {
                if (neighbor.getVisitedStatus()) {
                    return false;
                }
                neighbor.setVisitedStatus(true);
                territories.push_back(neighbor);
            }
        }
    }

    if (territories.empty()) {
        return false;
    }

    // Additional checks for continents and territory ownership
    return true;
}

std::ostream& operator<<(std::ostream& os, const Map& map) {
    os << "Map contains " << map.getContinents().size() << " continents.";
    return os;
}




//DEFINING CLASS MEMBERS FOR MAP_LOADER

MapLoader::MapLoader(std::string filePath) : filePath(filePath) {}
static inline std::string trim(const std::string& s) {
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }

    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

Map* MapLoader::loadMap() {

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "in file not open" << std::endl;
        throw std::runtime_error("Failed to open the map file.");
    }
    Map* map = new Map();
    std::string line;
    bool readingContinents = false;
    bool readingTerritories = false;
    std::vector<std::pair<std::string, std::vector<std::string>>> pendingAdjacencies;

    std::vector<Continent> continents;

    while (getline(file, line)) {
        line = trim(line);

        if (line.empty()) continue;

        // Check if we are entering a new section
        if (line == "[Continents]") {

            readingContinents = true;
            readingTerritories = false;
            continue;
        }

        if (line == "[Territories]") {

            readingContinents = false;
            readingTerritories = true;
            map->setContinents(continents);
            continue;
        }
        if (readingContinents) {
            // Format: ContinentName=ArmyValue (ArmyValue not needed)
            std::stringstream ss(line);
            std::string continentName;
            getline(ss, continentName, '=');

            Continent* continent = new Continent(continentName);
            continents.push_back(*continent);
        }

        if (readingTerritories) {
            // Format: TerritoryName, X, Y, ContinentName, AdjacentTerritory1, AdjacentTerritory2, ...
            std::stringstream ss(line);

            std::string territoryName, continentName, temp;
            int x, y;

            // Parse the territory name
            getline(ss, territoryName, ',');
            // Parse the X and Y (which we ignore for now)
            ss >> x;
            ss.ignore(1); // Skip comma
            ss >> y;
            ss.ignore(1); // Skip comma

            // Parse the continent name
            getline(ss, continentName, ',');

            // Check if the continent exists in the map
            Continent* continent = nullptr;
            for (Continent c : map->getContinents()) {
                if (c.getName() == continentName) {
                    continent = &c;
                    break;
                }
            }
            if (!continent) {
                throw std::runtime_error("Continent " + continentName + " not found for territory " + territoryName);
            }

            // Create the territory and add it to the map and the continent
            Territory* territory = new Territory(territoryName);
            continent->addTerritory(*territory);
            std::cout << *territory << std::endl;

            // Parse the adjacent territories and store for later linking
            std::vector<Territory> neighbors;
            while (getline(ss, temp, ',')) {
                neighbors.push_back(*(new Territory(temp)));
            }
        }
    }

    file.close();
    return map;
}

std::ostream& operator<<(std::ostream& os, const MapLoader& mapLoader) {
    os << "MapLoader loading file: " << mapLoader.getFilePath();
    return os;
}

std::string MapLoader::getFilePath() const {
    return this->filePath;
}