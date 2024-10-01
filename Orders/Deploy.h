#ifndef DEPLOY_H
#define DEPLOY_H
#include "Order.h"

class Deploy : public Order {
private:
    int armyUnits;
    std::string targetTerritory;

public:
    Deploy(int armyUnits, std::string targetTerritory);

    int getArmyUnits();
    std::string getTargetTerritory();

    bool validate();
    void execute();
    void summary();
};

#endif