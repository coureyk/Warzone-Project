#include "Player.h"
#include <iostream>


Player::Player(std::vector<Territory>* territories, std::vector<Order>* orders, std::vector<Card>* cards) {

	this->territories = territories;

	this->orders = orders;

	//this->cards = cards;

}

Player::Player() {

	territories = new std::vector<Territory>;

	orders = new std::vector<Order>;

	cards = new std::vector<Card>;

}

std::vector<Territory>* Player::toDefend() {



}

std::vector<Territory>* Player::toAttack() {


}

void Player::issueOrder() {

	std::cout << "Which order would you like to issue?";

	Deploy* deploy;

	ordersList->addLast(deploy);








}