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

class Advance : public Order {
private:
    int armyUnits;
    std::string sourceTerritory;
    std::string targetTerritory;

public:
    Advance(int armyUnits, std::string sourceTerritory, std::string targetTerritory);

    int getArmyUnits();
    std::string getSourceTerritory();
    std::string getTargetTerritory();

    bool validate();
    void execute();
    void summary();
};

class Bomb : public Order {
private:
    std::string targetTerritory;

public:
    Bomb(std::string targetTerritory);

    std::string getTargetTerritory();

    bool validate();
    void execute();
    void summary();
};

class Blockade : public Order {
private:
    std::string targetTerritory;

public:
    Blockade(std::string targetTerritory);

    std::string getTargetTerritory();

    bool validate();
    void execute();
    void summary();
};

class Airlift : public Order {
private:
    int armyUnits;
    std::string sourceTerritory;
    std::string targetTerritory;

public:
    Airlift(int armyUnits, std::string sourceTerritory, std::string targetTerritory);

    int getArmyUnits();
    std::string getSourceTerritory();
    std::string getTargetTerritory();

    bool validate();
    void execute();
    void summary();
};

class Negotiate : public Order {
private:
    std::string sourcePlayer;
    std::string targetPlayer;

public:
    Negotiate(std::string sourcePlayer, std::string targetPlayer);

    std::string getSourcePlayer();
    std::string getTargetPlayer();

    bool validate();
    void execute();
    void summary();
};



#endif
