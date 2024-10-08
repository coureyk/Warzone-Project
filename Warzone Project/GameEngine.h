#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <string>
#include <iostream>
#include <cstdio>

class GameEngine
{
public:
    // Method to display the available options based on the current state
    void displayNextPath(int currentState);

    void startup();// Method to start the game

    bool validCommandInput(const std::string command);//makes sure the user inputed a valid phrase

    // method to set the state based on the command
    void setState(const std::string command);
    /*The state represents a certain phase of the game and dictates what are the valid actions
or user commands that take place in this phase. Some actions or commands may eventually
trigger a transition to another state, which is what controls the flow of the game.
command -> state it goes to
start or play -> START
loadmap -> MAP_LOADED
validatemap -> MAP_VALIDATED
addplayer -> PLAYERS_ADDED
assigncountries or endexecorders -> ASSIGN_REINFORCEMENTS
issueorder -> ISSUE_ORDERS
endissueorders or execorders -> EXECUTE_ORDERS
win -> WIN
*/
    enum states {
        INITIALISED = -10,
        START = 00,
        MAP_LOADED = 10,
        MAP_VALIDATED = 20,
        PLAYERS_ADDED = 30,
        ASSIGN_REINFORCEMENTS = 40,
        ISSUE_ORDERS = 50,
        EXECUTE_ORDERS = 60,
        WIN = 70,
        FINISHED = 80
    };

    // Static variable to hold the current game state
    static int state;
};

/*Free function named testGameStates() that allows the user to type command strings on the console, whose result is
to trigger some state transitions as depicted in the state transition diagram presented below. Any command string
entered that does not correspond to an outgoing edge of the current state should be rejected.*/
void testGameStates();

#endif
