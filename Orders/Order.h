#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <iostream>
#include <vector>

class Order {
private:
    std::string orderType;
public:
    //Default constructor included automatically
    virtual bool validate() = 0;
    virtual void execute() = 0;
    virtual void summary() = 0;
    std::string getOrderType();
    void setOrderType(std::string orderType);
};

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
