#include "Cards.h"
#include "CardsDriver.cpp"

#include "GameEngine.h"

#include "MapDriver.cpp""

int main() {
    std::cout << "testCards() is invoked\n\n\n";
    testCards();

    std::cout << "\n\n\ntestGameStates() is invoked\n\n\n";
    testGameStates();

    /* File reading causes error
    std::cout << "\n\n\ntestLoadMaps() is invoked";
    testLoadMaps();
    */
}
