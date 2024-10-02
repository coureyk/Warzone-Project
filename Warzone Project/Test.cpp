#include "Player.h"
#include <vector>
#include "Territory.h"

int main() {


	std::vector<Territory>* territories = new std::vector<Territory>;

	territories->push_back(std::string("Alaska"));


	Player* player1 = new Player(territories,NULL,NULL);






}
