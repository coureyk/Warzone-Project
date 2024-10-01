#include "Order.h"
#include "OrdersList.h"

static void testOrdersLists() {
    Deploy o1(5, "Turkey");
    Advance o2(10, "Switzerland", "Germany");
    Bomb o3("Canada");
    Blockade o4("China");
    Airlift o5(10, "Mexico", "Wisconsin");
    Negotiate o6("Ricky", "Liam");

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

