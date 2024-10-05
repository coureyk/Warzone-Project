#include "Player.h"
#include <vector>

int main() {

	std::vector<Territory>* territories = new std::vector<Territory>;

	std::string s = "";

	Territory* territory1 = new Territory(s);

	territories->push_back(*territory1);
	
	Card* card1 = new Card(BOMB);

	Hand* hand1 = new Hand;

	hand1->addCard(card1);

	OrdersList* list = new OrdersList;

	Deploy* order1 = new Deploy(1,std::string("Alaska"));

	list->addLast(order1);

	Player* player1 = new Player(*territories, *list, *hand1);

	player1->issueOrder();

	
}
