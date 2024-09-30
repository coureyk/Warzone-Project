#include "Order.h"

std::string Order::getOrderType() {
    return this->orderType;
}

void Order::setOrderType(std::string orderType) {
    this->orderType = orderType;
}