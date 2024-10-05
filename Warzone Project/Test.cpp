#include "Cards.h"
#include "CardsDriver.h"

#include "GameEngine.h"

#include "OrdersDriver.h"

#include "Player.h"

#include "MapDriver.h"
void waitForEnter() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore();  // Ignores any leftover input (like a previous newline)
    std::cin.get();     // Waits for the user to press Enter
}
int main() {
    //File reading causes error
    std::cout << "\n\n\ntestLoadMaps() is invoked\n\n\n";
    waitForEnter();
    testLoadMaps();

    std::cout << "\n\n\ntestPlayers() is invoked\n\n\n";
    waitForEnter();
    testPlayers();


    std::cout << "\n\n\ntestOrdersLists() is invoked\n\n\n";
    waitForEnter();
    testOrdersLists();

    std::cout << "testCards() is invoked\n\n\n";
    waitForEnter();
    testCards();

    std::cout << "\n\n\ntestGameStates() is invoked\n\n\n";
    waitForEnter();
    testGameStates();
}