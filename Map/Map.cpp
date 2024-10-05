#include "Map.h"

std::vector<Continent> Map::continents{};

Map::Map(std::vector<Continent> continents) {
    Map::continents = continents;
}

std::vector<Continent> Map::getContinents() {
    return Map::continents;
}

void Map::setContinents(std::vector<Continent> continents) {
    Map::continents = continents;
}

bool Map::validate() {
    return true;
}

bool Map::terrtoryChecked() {
    return false;
}

validate (){

bool connectedMap =False;
bool connectedContinent=False;
bool TerritoryDuplicity=False;
int count1edge=0;
int count2edges=0;
int numOfTerritory=0;
int numOfContient=0;
std::vector<string> arr;


for (int i = 0; i < Map::getContinents().size(); i++) {
        
        std::cout << "Continent: " << Map::getContinents().at(i).getName() << "\n";
        numOfContients=numOfContients+getContinents.size();
        std::cout <<;
        for (int j = 0; j < Map::getContinents().at(i).getTerritories().size(); j++) {
            arr.push_back(getContinents().at(i).getTerritories().at(j).getName())
            
            if (getContinents().at(i).getTerritories().at(j).get_ref_count()>=1) {
                 count1edge++;
            }
            if (getContinents().at(i).getTerritories().at(j)get_ref_count()>=2){
                count2edges++;
            }
            numOfTerritory=getContinents().at(i).getTerritories().size()+numOfTerritory;
        }

        std::connectedMap=(count1edge>=numOfTerritory);
        std::connectedContinent=(count2edges>numOfContients*2);
      
    }


std::sort(arr.begin(), arr.end());
for(int i = 0; i < arr.size() ; i++) {
    if (arr[i] == arr[i + 1]) {
        TerritoryDuplicity=True;
        
    }
}

std::cout<<"This a connected map: "<<connectedMap<<',\n'
std::cout<<"The continents are connected: "<<connectedContinent<<',\n'
std::cout<<"The map doesn't have duplicates: "<<TerritoryDuplicity<<endl



}