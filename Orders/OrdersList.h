#ifndef ORDERSLIST_H
#define ORDERSLIST_H
#include "Order.h"

class OrdersList {
private:
    class Node {
    private:
        Order* element;
        Node* prev;
        Node* next;

    public:
        Node();
        Node(Order* element, Node* prev, Node* next);
        
        Order* getElement();
        Node* getPrev();
        Node* getNext();
        void setPrev(Node* prev);
        void setNext(Node* next);
    };

    Node* header;
    Node* trailer;
    int size = 0;

    void addBetween(Order* element, Node* predecessor, Node* successor);

public:
    OrdersList();

    int getSize();
    bool isEmpty();
    Node* first();
    Node* last();
    void addLast(Order* element);
    Order* remove(Node* node);
    void move(int currentPos, int targetPos);
    void getContents();
};

#endif