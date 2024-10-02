#include "Order.h"

//DEFINING CLASS MEMBERS FOR ORDER
std::string Order::getOrderType() {
    return this->orderType;
}

void Order::setOrderType(std::string orderType) {
    this->orderType = orderType;
}

//DEFINING CLASS MEMBERS FOR DEPLOY
Deploy::Deploy(int armyUnits, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->targetTerritory = targetTerritory;
    this->setOrderType("Deploy");
}

int Deploy::getArmyUnits() {
    return this->armyUnits;
}

std::string Deploy::getTargetTerritory() {
    return this->targetTerritory;
}

bool Deploy::validate() {
    return true;
}

void Deploy::execute() {

}

void Deploy::summary() {
    std::cout << "Army Units: " << getArmyUnits() << "\nTarget Territory: " << getTargetTerritory() << "\n";
}

//DEFINING CLASS MEMBERS FOR ADVANCE
Advance::Advance(int armyUnits, std::string sourceTerritory, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->sourceTerritory = sourceTerritory;
    this->targetTerritory = targetTerritory;
}

int Advance::getArmyUnits() {
    return this->armyUnits;
}

std::string Advance::getSourceTerritory() {
    return this->sourceTerritory;
}

std::string Advance::getTargetTerritory() {
    return this->targetTerritory;
}

bool Advance::validate() {
    return true;
}

void Advance::execute() {

}

void Advance::summary() {
    std::cout << "Army Units: " << getArmyUnits() << "\nSource Territory: " << getSourceTerritory() << "\nTarget Territory : " << getTargetTerritory() << "\n";
}

//DEFINING CLASS MEMBERS FOR BOMB
Bomb::Bomb(std::string targetTerritory) {
    this->targetTerritory = targetTerritory;
}

std::string Bomb::getTargetTerritory() {
    return this->targetTerritory;
}

bool Bomb::validate() {
    return true;
}

void Bomb::execute() {

}

void Bomb::summary() {
    std::cout << "Target Territory : " << getTargetTerritory() << "\n";
}

//DEFINING CLASS MEMBERS FOR BLOCKADE
Blockade::Blockade(std::string targetTerritory) {
    this->targetTerritory = targetTerritory;
}

std::string Blockade::getTargetTerritory() {
    return this->targetTerritory;
}

bool Blockade::validate() {
    return true;
}

void Blockade::execute() {

}

void Blockade::summary() {
    std::cout << "Target Territory : " << getTargetTerritory() << "\n";
}

Airlift::Airlift(int armyUnits, std::string sourceTerritory, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->sourceTerritory = sourceTerritory;
    this->targetTerritory = targetTerritory;
}

int Airlift::getArmyUnits() {
    return this->armyUnits;
}

std::string Airlift::getSourceTerritory() {
    return this->sourceTerritory;
}

std::string Airlift::getTargetTerritory() {
    return this->targetTerritory;
}

bool Airlift::validate() {
    return true;
}

void Airlift::execute() {

}

void Airlift::summary() {
    std::cout << "Army Units: " << getArmyUnits() << "\nSource Territory: " << getSourceTerritory() << "\nTarget Territory : " << getTargetTerritory() << "\n";
}

Negotiate::Negotiate(std::string sourcePlayer, std::string targetPlayer) {
    this->sourcePlayer = sourcePlayer;
    this->targetPlayer = targetPlayer;
}

std::string Negotiate::getSourcePlayer() {
    return this->sourcePlayer;
}

std::string Negotiate::getTargetPlayer() {
    return this->targetPlayer;
}

bool Negotiate::validate() {
    return true;
}

void Negotiate::execute() {

}

void Negotiate::summary() {
    std::cout << "Source Player: " << getSourcePlayer() << "\nTarget Player: " << getTargetPlayer() << "\n";
}