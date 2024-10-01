#include "Order.h"
#include "OrdersList.h"

int main() {
    Deploy o1(5, "Turkey");
    Advance o2(10, "Germany", "Russia");
    Bomb o3("Canada");
    Blockade o4("Mexico");
    Airlift o5(10, "Wisconsin", "Tallahassee");
    Negotiate o6("Kevin", "Liam");

    OrdersList list;

    list.addLast(&o1);
    list.addLast(&o2);
    list.addLast(&o3);
    list.addLast(&o4);
    list.addLast(&o5);
    list.addLast(&o6);

    list.move(1, 3);

    list.getContents();
}