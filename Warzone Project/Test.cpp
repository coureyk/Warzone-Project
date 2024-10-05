#include "OrdersDriver.h";

#include "Cards.h"
#include "CardsDriver.cpp"

#include "GameEngine.h"

#include "Player.h"

#include "mapDriver.cpp"


int main() {
    std::cout << "TESTING ORDER METHODS\n\n\n";
    testOrdersLists();

    std::cout << "\n\n\nTESTING CARDS METHODS\n\n\n";
    testCards();

    std::cout << "\n\n\nTESTING GAME_ENGINE METHODS";
    testGameStates();

    std::cout << "\n\n\nTESTING PLAYER METHODS";
    testPlayers();

    std::cout << "\n\n\nTESTING MAP METHODS";
    testLoadMaps();
}
