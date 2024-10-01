#include "Order.h"

std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << order.summary();
    return os;
}

//DEFINING CLASS MEMBERS FOR ORDER
std::string Order::getOrderType() const {
    return this->orderType;
}

void Order::setOrderType(std::string orderType) {
    this->orderType = orderType;
}

bool Order::getExecutionStatus() const {
    return this->hasExecuted;
}

void Order::setExecutionStatus(bool hasExecuted) {
    this->hasExecuted = hasExecuted;
}

//DEFINING CLASS MEMBERS FOR DEPLOY
Deploy::Deploy(int armyUnits, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->targetTerritory = targetTerritory;
    this->setOrderType("Deploy");
}

int Deploy::getArmyUnits() const {
    return this->armyUnits;
}

std::string Deploy::getTargetTerritory() const {
    return this->targetTerritory;
}

bool Deploy::validate() {
    return true;
}

void Deploy::execute() {

}

std::string Deploy::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Put " + std::to_string(this->getArmyUnits()) + " army units on " + this->getTargetTerritory() + "\n";
    }
    else {
        return "Deploy Execution Summary";
    }
}

//DEFINING CLASS MEMBERS FOR ADVANCE
Advance::Advance(int armyUnits, std::string sourceTerritory, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->sourceTerritory = sourceTerritory;
    this->targetTerritory = targetTerritory;
    this->setOrderType("Advance");
}

int Advance::getArmyUnits() const {
    return this->armyUnits;
}

std::string Advance::getSourceTerritory() const {
    return this->sourceTerritory;
}

std::string Advance::getTargetTerritory() const {
    return this->targetTerritory;
}

bool Advance::validate() {
    return true;
}

void Advance::execute() {

}

std::string Advance::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Move " + std::to_string(this->getArmyUnits()) + " army units from " + this->getSourceTerritory() + " to " + this->getTargetTerritory() + "\n";
    }
    else {
        return "Advance Execution Summary";
    }
}

//DEFINING CLASS MEMBERS FOR BOMB
Bomb::Bomb(std::string targetTerritory) {
    this->targetTerritory = targetTerritory;
    this->setOrderType("Bomb");
}

std::string Bomb::getTargetTerritory() const {
    return this->targetTerritory;
}

bool Bomb::validate() {
    return true;
}

void Bomb::execute() {

}

std::string Bomb::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Destroy half of the army units located on " + this->getTargetTerritory() + ". This order can only be issued if a player has the bomb card in their hand.\n";
    }
    else {
        return "Bomb Execution Summary";
    }
}

//DEFINING CLASS MEMBERS FOR BLOCKADE
Blockade::Blockade(std::string targetTerritory) {
    this->targetTerritory = targetTerritory;
    this->setOrderType("Blockade");
}

std::string Blockade::getTargetTerritory() const {
    return this->targetTerritory;
}

bool Blockade::validate() {
    return true;
}

void Blockade::execute() {

}

std::string Blockade::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Triple the number of army units on " + this->getTargetTerritory() + " and make it a neutral territory. This order can only be issued if a player has the blockade card in their hand.\n";
    }
    else {
        return "Blockade Execution Summary";
    }
}

Airlift::Airlift(int armyUnits, std::string sourceTerritory, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->sourceTerritory = sourceTerritory;
    this->targetTerritory = targetTerritory;
    this->setOrderType("Airlift");
}

int Airlift::getArmyUnits() const {
    return this->armyUnits;
}

std::string Airlift::getSourceTerritory() const{
    return this->sourceTerritory;
}

std::string Airlift::getTargetTerritory() const {
    return this->targetTerritory;
}

bool Airlift::validate() {
    return true;
}

void Airlift::execute() {

}

std::string Airlift::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Advance " + std::to_string(this->getArmyUnits()) + " army units from " + this->getSourceTerritory() + " to " + this->getTargetTerritory() + ". This order can only be issued if a player has the airlift card in their hand.\n";
    }
    else {
        return "Airlift Execution Summary";
    }
}

Negotiate::Negotiate(std::string sourcePlayer, std::string targetPlayer) {
    this->sourcePlayer = sourcePlayer;
    this->targetPlayer = targetPlayer;
    this->setOrderType("Negotiate");
}

std::string Negotiate::getSourcePlayer() const {
    return this->sourcePlayer;
}

std::string Negotiate::getTargetPlayer() const {
    return this->targetPlayer;
}

bool Negotiate::validate() {
    return true;
}

void Negotiate::execute() {

}

std::string Negotiate::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Prevent attacks between " + this->getSourcePlayer() + " and " + this->getTargetPlayer() + " until the end of the turn. This order can ony be issued if a player has the diplomacy card in their hand.\n";
    }
    else {
        return "Negotiate Execution Summary";
    }
}