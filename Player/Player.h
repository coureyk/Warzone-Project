#pragma once

#include <vector>
#include "Territory.h"
#include "Order.h"
//#include "Card.h"


class Player {

private:
	
	std::vector<Territory>* territories;

	std::vector<Order>* orders;

	//std::vector<Cards>* cards;

public:

	Player();

	Player(std::vector<Territory>* territories, std::vector<Order>* orders, std::vector<Card>* cards);

	std::vector<Territory>* toDefend();

	std::vector<Territory>* toAttack();

	Order issueOrder();



	



};