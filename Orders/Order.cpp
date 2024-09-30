#include "Order.h"

//Defining class members for Order
std::string Order::getOrderType() {
    return this->orderType;
}

void Order::setOrderType(std::string orderType) {
    this->orderType = orderType;
}

//Defining class members for Deploy
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