
#include "GameEngine_H.h"
/* Implement a group of C++ classes that implements a game engine that controls the flow of 
the game by using the notion of state, transition, and command. 
 */

/*The state represents a certain phase of the game and dictates what are the valid actions
or user commands that take place in this phase. Some actions or commands may eventually
trigger a transition to another state, which is what controls the flow of the game. */
std::string state;

/*
* loadmap until user is satisfied
* -map loaded -> validatemap -> mapvalidated
* -
* -addplayer until user is satisfied -> assigncountries ->
* 
* -continue to play
*/
void GameEngine::startup() {


}

/*
loop:
	~assign reinforcement -> issue order
	~issue orders until satisfied -> endissueorders
	~execute orders until satisifed -> 
		end execorders -> assign reinforcement
		OR
		Win
Win
	>End 
	OR
	>Re-play back to start
*/
void GameEngine::play() {
}

