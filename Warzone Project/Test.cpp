#include "Cards.h"
#include "CardsDriver.cpp"

#include "GameEngine.h"

#include "MapDriver.cpp"

#include "OrdersDriver.h"

int main() {
    std::cout << "testCards() is invoked\n\n\n";
    testCards();

    std::cout << "\n\n\ntestGameStates() is invoked\n\n\n";
    testGameStates();

    std::cout << "\n\n\ntestOrdersLists() is invoked\n\n\n";
    testOrdersLists();

    /* File reading causes error
    std::cout << "\n\n\ntestLoadMaps() is invoked";
    testLoadMaps();
    */
}
