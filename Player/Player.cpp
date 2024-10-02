#include "Player.h"
#include <iostream>


Player::Player(std::vector<Territory>*territories,OrdersList* ordersList, Hand* hand) {

	this->territories = territories;

	this->ordersList = ordersList;

	this->hand = hand;

}

Player::Player() {

	territories = new std::vector<Territory>;

	ordersList = new OrdersList;

	hand = new Hand;

}

std::vector<Territory>* Player::toDefend() {

	std::vector<Territory>* territories = new std::vector<Territory>();
	return territories;

}

std::vector<Territory>* Player::toAttack() {

	std::vector<Territory>* territories = new std::vector<Territory>();
	return territories;

}

void Player::issueOrder() {

	std::cout << R"HERE(Which order would you like to issue?
\nEnter 1 for Deploy
\nEnter 2 for Advance
\nEnter 3 for Bomb
\nEnter 4 for Blockade
\nEnter 5 for Airlift
\nEnter 6 for Negotiate\n)HERE";

	int input = 0;

	std::cin >> input;

	switch (input) {

	case 1:
		Deploy * deploy = new Deploy(0, NULL);
		ordersList->addLast(deploy);
		break;
	case 2:
		Advance * advance = new Advance(0,NULL,NULL);
		ordersList->addLast(advance);
		break;
	case 3:
		Bomb* bomb = new Bomb(0);
		ordersList->addLast(bomb);
		break;
	case 4:
		Blockade * blockade = new Blockade(NULL);
		ordersList->addLast(blockade);
		break;
	case 5:
		Airlift * airlift = new Airlift(0,NULL,NULL);
		ordersList->addLast(airlift);
		break;
	case 6:
		Negotiate * negotiate = new Negotiate(NULL,NULL);
		ordersList->addLast(negotiate);
		break;
	}

	




}