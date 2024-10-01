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



}

std::vector<Territory>* Player::toAttack() {



}

void Player::issueOrder() {

	std::cout << "Which order would you like to issue?";

	Deploy* deploy = new Deploy;

	ordersList->addLast(deploy);




}