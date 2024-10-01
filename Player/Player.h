#pragma once

#include <vector>
#include "Territory.h"
#include "Order.h"
#include "Card.h"
#include "OrdersList.h"


class Player {

private:

	std::vector<Territory>* territories;

	OrdersList* ordersList;

	Hand* hand;

public:

	Player();

	Player(std::vector<Territory>* territories, std::vector<Order>* orders, std::vector<Card>* cards);

	std::vector<Territory>* toDefend();

	std::vector<Territory>* toAttack();

	void issueOrder();







};