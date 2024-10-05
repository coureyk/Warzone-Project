#include "Cards.h"
#include "CardsDriver.cpp"

#include "GameEngine.h"

#include "OrdersDriver.h"

#include "Player.h"

#include "MapDriver.cpp"

int main() {
    std::cout << "testCards() is invoked\n\n\n";
    testCards();

    std::cout << "\n\n\ntestGameStates() is invoked\n\n\n";
    testGameStates();

    std::cout << "\n\n\ntestOrdersLists() is invoked\n\n\n";
    testOrdersLists();

    std::cout << "\n\n\ntestPlayers() is invoked\n\n\n";
    testPlayers();

    /* File reading causes error
    std::cout << "\n\n\ntestLoadMaps() is invoked";
    testLoadMaps();
    */
}
