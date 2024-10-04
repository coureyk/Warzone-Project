#pragma once
#include <vector>
#include "Territory.h"
#include "Order.h"
#include "Card.h"
#include "OrdersList.h"


class Player {

protected:

	std::vector<Territory>* territories;

	OrdersList* ordersList;

	Hand* hand;

public:

	Player();

	Player(const Player& player);

	Player(const std::vector<Territory>& territories, const OrdersList& ordersList, const Hand& hand);

	std::vector<Territory>* toDefend();

	std::vector<Territory>* toAttack();

	void issueOrder();

	Player& operator=(const Player& otherPlayer);

	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	
	
};

