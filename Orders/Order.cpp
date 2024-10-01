#include "Order.h"

std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << order.summary();
    return os;
}

//DEFINING CLASS MEMBERS FOR ORDER
std::string Order::getOrderType() const {
    return this->orderType;
}

bool Order::getExecutionStatus() const {
    return this->hasExecuted;
}

void Order::setOrderType(std::string orderType) {
    this->orderType = orderType;
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

Deploy::Deploy(Deploy& other)
{
    armyUnits = other.getArmyUnits();
    targetTerritory = other.getTargetTerritory();
}

Deploy& Deploy::operator=(const Deploy& other)
{
    // Check for self-assignment
    if (this != &other) {
        armyUnits = other.getArmyUnits();
        targetTerritory = other.getTargetTerritory();
    }
    return *this;
}

int Deploy::getArmyUnits() const {
    return this->armyUnits;
}

std::string Deploy::getTargetTerritory() const {
    return this->targetTerritory;
}

std::string Deploy::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Put " + std::to_string(this->getArmyUnits()) + " army units on " + this->getTargetTerritory() + "\n";
    }
    else {
        return "Deploy Execution Summary";
    }
}

bool Deploy::validate() {
    return true;
}

void Deploy::execute() {

}

//DEFINING CLASS MEMBERS FOR ADVANCE
Advance::Advance(int armyUnits, std::string sourceTerritory, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->sourceTerritory = sourceTerritory;
    this->targetTerritory = targetTerritory;
    this->setOrderType("Advance");
}


Advance::Advance(Advance& other)
{
    armyUnits = other.getArmyUnits();
    sourceTerritory = other.getSourceTerritory();
    targetTerritory = other.getTargetTerritory();
}

Advance& Advance::operator=(const Advance& other)
{
    // Check for self-assignment
    if (this != &other) {
        armyUnits = other.getArmyUnits();
        sourceTerritory = other.getSourceTerritory();
        targetTerritory = other.getTargetTerritory();
    }
    return *this;
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

std::string Advance::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Move " + std::to_string(this->getArmyUnits()) + " army units from " + this->getSourceTerritory() + " to " + this->getTargetTerritory() + "\n";
    }
    else {
        return "Advance Execution Summary";
    }
}

bool Advance::validate() {
    return true;
}

void Advance::execute() {

}

//DEFINING CLASS MEMBERS FOR BOMB
Bomb::Bomb(std::string targetTerritory) {
    this->targetTerritory = targetTerritory;
    this->setOrderType("Bomb");
}

Bomb::Bomb(Bomb& other)
{
    targetTerritory = other.getTargetTerritory();
}

Bomb& Bomb::operator=(const Bomb& other)
{
    // Check for self-assignment
    if (this != &other) {
        targetTerritory = other.getTargetTerritory();
    }
    return *this;
}

std::string Bomb::getTargetTerritory() const {
    return this->targetTerritory;
}

std::string Bomb::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Destroy half of the army units located on " + this->getTargetTerritory() + ". This order can only be issued if a player has the bomb card in their hand.\n";
    }
    else {
        return "Bomb Execution Summary";
    }
}

bool Bomb::validate() {
    return true;
}

void Bomb::execute() {

}

//DEFINING CLASS MEMBERS FOR BLOCKADE
Blockade::Blockade(std::string targetTerritory) {
    this->targetTerritory = targetTerritory;
    this->setOrderType("Blockade");
}


Blockade::Blockade(Blockade& other)
{
    targetTerritory = other.getTargetTerritory();
}

Blockade& Blockade::operator=(const Blockade& other)
{
    // Check for self-assignment
    if (this != &other) {
        targetTerritory = other.getTargetTerritory();
    }
    return *this;
}

std::string Blockade::getTargetTerritory() const {
    return this->targetTerritory;
}

std::string Blockade::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Triple the number of army units on " + this->getTargetTerritory() + " and make it a neutral territory. This order can only be issued if a player has the blockade card in their hand.\n";
    }
    else {
        return "Blockade Execution Summary";
    }
}

bool Blockade::validate() {
    return true;
}

void Blockade::execute() {

}

Airlift::Airlift(int armyUnits, std::string sourceTerritory, std::string targetTerritory) {
    this->armyUnits = armyUnits;
    this->sourceTerritory = sourceTerritory;
    this->targetTerritory = targetTerritory;
    this->setOrderType("Airlift");
}


Airlift::Airlift(Airlift& other)
{
    armyUnits = other.getArmyUnits();
    sourceTerritory = other.getSourceTerritory();
    targetTerritory = other.getTargetTerritory();
}

Airlift& Airlift::operator=(const Airlift& other)
{
    // Check for self-assignment
    if (this != &other) {
        armyUnits = other.getArmyUnits();
        sourceTerritory = other.getSourceTerritory();
        targetTerritory = other.getTargetTerritory();
    }
    return *this;
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

std::string Airlift::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Advance " + std::to_string(this->getArmyUnits()) + " army units from " + this->getSourceTerritory() + " to " + this->getTargetTerritory() + ". This order can only be issued if a player has the airlift card in their hand.\n";
    }
    else {
        return "Airlift Execution Summary";
    }
}

bool Airlift::validate() {
    return true;
}

void Airlift::execute() {

}

Negotiate::Negotiate(std::string sourcePlayer, std::string targetPlayer) {
    this->sourcePlayer = sourcePlayer;
    this->targetPlayer = targetPlayer;
    this->setOrderType("Negotiate");
}


Negotiate::Negotiate(Negotiate& other)
{
    sourcePlayer = other.getSourcePlayer();
    targetPlayer = other.getTargetPlayer();
}

Negotiate& Negotiate::operator=(const Negotiate& other)
{
    // Check for self-assignment
    if (this != &other) {
        sourcePlayer = other.getSourcePlayer();
        targetPlayer = other.getTargetPlayer();
    }
    return *this;
}

std::string Negotiate::getSourcePlayer() const {
    return this->sourcePlayer;
}

std::string Negotiate::getTargetPlayer() const {
    return this->targetPlayer;
}

std::string Negotiate::summary() const {
    if (!this->getExecutionStatus()) {
        return "Order Type: " + this->getOrderType() + "\nSummary: Prevent attacks between " + this->getSourcePlayer() + " and " + this->getTargetPlayer() + " until the end of the turn. This order can ony be issued if a player has the diplomacy card in their hand.\n";
    }
    else {
        return "Negotiate Execution Summary";
    }
}

bool Negotiate::validate() {
    return true;
}

void Negotiate::execute() {

}