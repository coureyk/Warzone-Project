#include "Order.h"
#include "OrdersList.h"

static void testOrdersLists() {
    Deploy o1(5, "Turkey");
    Deploy o2(10, "Germany");
    Deploy o3(15, "Canada");

    OrdersList list;

    list.addLast(&o1);
    list.addLast(&o2);
    list.addLast(&o3);

    list.move(1, 3);

    list.getContents();
}

