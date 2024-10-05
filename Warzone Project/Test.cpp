#include "Cards.h"
#include "CardsDriver.cpp"

#include "GameEngine.h"

#include "Player.h"


int main() {
    std::cout << "TESTING CARDS METHODS\n\n\n";
    testCards();

    std::cout << "\n\n\nTESTING GAME_ENGINE METHODS";
    testGameStates();

    std::cout << "\n\n\nTESTING PLAYER METHODS";
    testPlayers();


}
