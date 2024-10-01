#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <iostream>
#include <vector>

class Order {
private:
    std::string orderType;
    bool hasExecuted = false;

public:
    //Default constructor included automatically
    virtual bool validate() = 0;
    virtual void execute() = 0;
    
    virtual std::string summary() const = 0;
    std::string getOrderType() const;
    bool getExecutionStatus() const; //Must be a constant function so it may be invoked by a const Deploy, Advance, ... object

    void setOrderType(std::string orderType);
    void setExecutionStatus(bool hasExecuted);
};

std::ostream& operator<<(std::ostream& os, const Order& order);

class Deploy : public Order {
private:
    int armyUnits;
    std::string targetTerritory;

public:
    Deploy(int armyUnits, std::string targetTerritory);
    Deploy(Deploy& other);
    Deploy& operator=(const Deploy& other);

    int getArmyUnits() const;
    std::string getTargetTerritory() const;
    std::string summary() const;

    bool validate();
    void execute();
};

class Advance : public Order {
private:
    int armyUnits;
    std::string sourceTerritory;
    std::string targetTerritory;

public:
    Advance(int armyUnits, std::string sourceTerritory, std::string targetTerritory);
    Advance(Advance& other);
    Advance& operator=(const Advance& other);

    int getArmyUnits() const;
    std::string getSourceTerritory() const;
    std::string getTargetTerritory() const;
    std::string summary() const;

    bool validate();
    void execute();
};

class Bomb : public Order {
private:
    std::string targetTerritory;

public:
    Bomb(std::string targetTerritory);
    Bomb(Bomb& other);
    Bomb& operator=(const Bomb& other);

    std::string getTargetTerritory() const;
    std::string summary() const;

    bool validate();
    void execute();
};

class Blockade : public Order {
private:
    std::string targetTerritory;

public:
    Blockade(std::string targetTerritory);
    Blockade(Blockade& other);
    Blockade& operator=(const Blockade& other);

    std::string getTargetTerritory() const;
    std::string summary() const;

    bool validate();
    void execute();
};

class Airlift : public Order {
private:
    int armyUnits;
    std::string sourceTerritory;
    std::string targetTerritory;

public:
    Airlift(int armyUnits, std::string sourceTerritory, std::string targetTerritory);
    Airlift(Airlift& other);
    Airlift& operator=(const Airlift& other);

    int getArmyUnits() const;
    std::string getSourceTerritory() const;
    std::string getTargetTerritory() const;
    std::string summary() const;

    bool validate();
    void execute();
};

class Negotiate : public Order {
private:
    std::string sourcePlayer;
    std::string targetPlayer;

public:
    Negotiate(std::string sourcePlayer, std::string targetPlayer);
    Negotiate(Negotiate& other);
    Negotiate& operator=(const Negotiate& other);

    std::string getSourcePlayer() const;
    std::string getTargetPlayer() const;
    std::string summary() const;

    bool validate();
    void execute();
};

#endif
