#include "Map.h"

Map::Map() {}

Map::Map(const Map& other)
    : territories(other.territories), continents(other.continents) {}

Map& Map::operator=(const Map& other) {
    if (this == &other) return *this; // Self-assignment check
    territories = other.territories;
    continents = other.continents;
    return *this;
}

Map::~Map() {}

void Map::addTerritory(Territory* territory) {
    territories.push_back(territory);
}

void Map::addContinent(Continent* continent) {
    continents.push_back(continent);
}
std::vector<Continent*> Map::getContinents() const {
    return continents;
}

std::vector<Territory*> Map::getTerritories() const {
    return territories;
}

bool Map::validate() const {
    // Perform a BFS to check if the map is a connected graph
    if (territories.empty()) return false;

    std::vector<bool> visited(territories.size(), false);
    std::queue<Territory*> q;
    q.push(territories[0]);
    visited[0] = true;

    while (!q.empty()) {
        Territory* current = q.front();
        q.pop();
        for (Territory* adj : current->getAdjacentTerritories()) {
            auto it = std::find(territories.begin(), territories.end(), adj);
            if (it != territories.end() && !visited[it - territories.begin()]) {
                visited[it - territories.begin()] = true;
                q.push(adj);
            }
        }
    }

    for (bool isVisited : visited) {
        if (!isVisited) return false;
    }

    // Additional checks for continents and territory ownership
    return true;
}

std::ostream& operator<<(std::ostream& os, const Map& map) {
    os << "Map contains " << map.territories.size() << " territories and " << map.continents.size() << " continents.";
    return os;
}


Territory::Territory(std::string name, Continent* continent, std::string owner, int armies)
    : name(name), continent(continent), owner(owner), armies(armies) {}

Territory::Territory(const Territory& other)
    : name(other.name), continent(other.continent), owner(other.owner), armies(other.armies), adjacentTerritories(other.adjacentTerritories) {}

Territory& Territory::operator=(const Territory& other) {
    if (this == &other) return *this; // Self-assignment check
    name = other.name;
    continent = other.continent;
    owner = other.owner;
    armies = other.armies;
    adjacentTerritories = other.adjacentTerritories;
    return *this;
}

Territory::~Territory() {}

void Territory::addAdjacentTerritory(Territory* territory) {
    adjacentTerritories.push_back(territory);
}

std::string Territory::getName() const {
    return name;
}

Continent* Territory::getContinent() const {
    return continent;
}

std::vector<Territory*> Territory::getAdjacentTerritories() const {
    return adjacentTerritories;
}

std::ostream& operator<<(std::ostream& os, const Territory& territory) {
    os << "Territory: " << territory.name << ", " << *territory.getContinent() << ", Owned by: " << territory.owner << ", Armies: " << territory.armies;
    return os;
}

Continent::Continent(std::string name) : name(name) {}

Continent::Continent(const Continent& other)
    : name(other.name), territories(other.territories) {}

Continent& Continent::operator=(const Continent& other) {
    if (this == &other) return *this; // Self-assignment check
    name = other.name;
    territories = other.territories;
    return *this;
}

Continent::~Continent() {}

void Continent::addTerritory(Territory* territory) {
    territories.push_back(territory);
}

std::string Continent::getName() const {
    return name;
}

std::vector<Territory*> Continent::getTerritories() const {
    return territories;
}

std::ostream& operator<<(std::ostream& os, const Continent& continent) {
    os << "Continent: " << continent.name;
    return os;
}

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

    std::cout << "Attempting to load map from: " << filePath << std::endl; // Print the file path

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
            continue;
        }
        if (readingContinents) {
            // Format: ContinentName=ArmyValue (ArmyValue not needed)
            std::stringstream ss(line);
            std::string continentName;
            getline(ss, continentName, '=');

            Continent* continent = new Continent(continentName);
            map->addContinent(continent);
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
            for (Continent* c : map->getContinents()) {
                if (c->getName() == continentName) {
                    continent = c;
                    break;
                }
            }
            if (!continent) {
                throw std::runtime_error("Continent " + continentName + " not found for territory " + territoryName);
            }

            // Create the territory and add it to the map and the continent
            Territory* territory = new Territory(territoryName, continent, "", 0); // Owner and armies set later
            map->addTerritory(territory);
            continent->addTerritory(territory);
            std::cout << *territory << std::endl;

            // Parse the adjacent territories and store for later linking
            std::vector<std::string> adjacentTerritories;
            while (getline(ss, temp, ',')) {
                adjacentTerritories.push_back(temp);
            }
            pendingAdjacencies.push_back({ territoryName, adjacentTerritories });
        }
    }

    // Now, process the pending adjacencies
    for (const auto& pair : pendingAdjacencies) {
        std::string territoryName = pair.first;
        std::vector<std::string> adjacents = pair.second;

        // Find the territory object by name
        Territory* territory = nullptr;
        for (Territory* t : map->getTerritories()) {
            if (t->getName() == territoryName) {
                territory = t;
                break;
            }
        }

        if (!territory) {
            throw std::runtime_error("Territory " + territoryName + " not found in map.");
        }

        // Link adjacent territories
        for (const std::string& adj : adjacents) {
            Territory* adjacentTerritory = nullptr;
            for (Territory* t : map->getTerritories()) {
                if (t->getName() == adj) {
                    adjacentTerritory = t;
                    break;
                }
            }

            if (!adjacentTerritory) {
                throw std::runtime_error("Adjacent territory " + adj + " not found for territory " + territoryName);
            }

            territory->addAdjacentTerritory(adjacentTerritory);
        }
    }

    file.close();
    return map;
}



std::ostream& operator<<(std::ostream& os, const MapLoader& mapLoader) {
    os << "MapLoader loading file: " << mapLoader.filePath;
    return os;
}
