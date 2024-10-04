#include "GameEngine.h"

/* Implement a group of C++ classes that implements a game engine that controls the flow of 
the game by using the notion of state, transition, and command. 
 */


int GameEngine::state = GameEngine::INITIALISED;

/*sets the state to the corresponding command*/
void GameEngine::setState(const std::string command) {
    std::cout << ("\nInput recieved\n") << std::endl;

      if(command == "start" || command == "play") GameEngine::state = states::START;
       
 else if (command == "loadmap") GameEngine::state = states::MAP_LOADED;
        
 else if (command == "validatemap") GameEngine::state = states::MAP_VALIDATED;
        
 else if (command == "addplayer") GameEngine::state = states::PLAYERS_ADDED;
        
 else if (command == "assigncountries" || command == "endexecorders") GameEngine::state = states::ASSIGN_REINFORCEMENTS;
        
 else if (command == "issueorder") GameEngine::state = states::ISSUE_ORDERS;
        
 else if (command == "endissueorders" || "execorders") GameEngine::state = states::EXECUTE_ORDERS;
        
 else if (command == "win")GameEngine::state = states::WIN;
}

/*Takes in the current command and displays the options the user has to proceed*/
void GameEngine::displayNextPath(int currentState) {
    switch (currentState) {
    case states::INITIALISED:   std::cout<<( "\nWelcome to the game, from here type the \"start\" command to enter the start state.\nFor reference, here is a list of all commands and the state they lead to : \ncommand->state it goes to\nstart or play->START\nloadmap->MAP_LOADED\nvalidatemap->MAP_VALIDATED\naddplayer->PLAYERS_ADDED\nassigncountries or endexecorders->ASSIGN_REINFORCEMENTS\nissueorder->ISSUE_ORDERS\nendissueorders or execorder->EXECUTE_ORDERS\nwin->WIN\n");break;
    case states::START:  std::cout << ("\nFrom START, you may use the \"loadmap\" command\n"); break;
    case states::MAP_LOADED: printf("\nFrom MAP_LOADED, you can use the \"loadmap\" or \"validatemap\" commands\n"); break;
    case states::MAP_VALIDATED: printf("\nFrom MAP_VALIDATED, you can use the \"addplayer\" command\n"); break;
    case states::PLAYERS_ADDED: printf("\nFrom PLAYERS_ADDED, you can use the \"addplayer\" or \"assigncountries\" commands\n");break;
    case states::ASSIGN_REINFORCEMENTS: printf("\nFrom ASSIGN_REINFORCEMENTS, you can use the \"issueorder\" command\n");break;
    case states::ISSUE_ORDERS: printf("\nFrom ISSUE_ORDERS, you can use the \"issueorder\" or \"endissueorders\" commands\n");break;
    case states::EXECUTE_ORDERS: printf("\nFrom EXECUTE_ORDERS, you can use the \"execorder\" or \"endexecorders\" or \"win\" commands\n"); break;\
    case states::WIN: printf("\nFrom WIN, you can use the \"end\" or \"play\" commands\n"); break;
    default: std::cout << "\nINCORRECT ENTRY, PLEASE ENTER VALID STATE\n" << std::endl;
    }
}

/*
* represents the begining of the game
*/
void GameEngine::startup() {
    do {
        //prompt user to imput command to acess a state and show them what they can go to
        displayNextPath(GameEngine::state);
        std::string command;
        do {
            std::getline(std::cin, command);
        } while (command != "start"); //make sure it is a valid command being input

        setState(command);
    } while (GameEngine::state != GameEngine::states::WIN);
}

//will take in the user's input and check if it follows a valid command
bool GameEngine::validateCommandInput(const std::string command) {
    /*
    command != "start" || command != "loadmap" || command != "play" ||
            command != "validatemap" || command != "addplayer" || command != "assigncountries" ||
            command != "endexecorders" || command != "issueorder" || command != "endissueorders" ||
            command != "win" || command != "execorders"*/
    return true;
}

void GameEngine::play() {
}


int main() {
    GameEngine gameEngine;
    gameEngine.startup();

    return 0;
}