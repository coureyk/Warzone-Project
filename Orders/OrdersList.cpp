#include "OrdersList.h"

OrdersList::Node::Node() {
    this->element = NULL;
    this->prev = NULL;
    this->next = NULL;
}

OrdersList::Node::Node(Order* element, Node* prev, Node* next) {
    this->element = element;
    this->prev = prev;
    this->next = next;
}

Order* OrdersList::Node::getElement() {
    return element;
}

OrdersList::Node* OrdersList::Node::getPrev() {
    return prev;
}

OrdersList::Node* OrdersList::Node::getNext() {
    return next;
}

void OrdersList::Node::setPrev(Node* prev) {
    this->prev = prev;
}

void OrdersList::Node::setNext(Node* next) {
    this->next = next;
}

OrdersList::OrdersList() {
    header = new Node();
    trailer = new Node(NULL, header, NULL);
    header->setNext(trailer);
}

int OrdersList::getSize() {
    return size;
}

bool OrdersList::isEmpty() {
    return OrdersList::getSize() == 0;
}

OrdersList::Node* OrdersList::first() {
    if (isEmpty()) {
        return NULL;
    }
    return header->getNext();
}

OrdersList::Node* OrdersList::last() {
    if (isEmpty()) {
        return NULL;
    }
    return trailer->getPrev();
}

void OrdersList::addLast(Order* element) {
    addBetween(element, trailer->getPrev(), trailer);
}

void OrdersList::addBetween(Order* element, Node* predecessor, Node* successor) {
    Node* newest = new Node(element, predecessor, successor);
    predecessor->setNext(newest);
    successor->setPrev(newest);
    size++;
}

Order* OrdersList::remove(Node* node) {
    if (isEmpty()) {
        return NULL;
    }
    Node* predecessor = node->getPrev();
    Node* successor = node->getNext();
    predecessor->setNext(successor);
    successor->setPrev(predecessor);
    size--;
    return node->getElement();
}

void OrdersList::move(int currentPos, int targetPos) {
    Node* currentNode = header->getNext();
    Node* targetNode = currentNode;
    bool currentNodeFound = false;
    bool targetNodeFound = false;

    for (int i = 1; i <= getSize(); i++) {
        if (i != currentPos && currentNodeFound != true) {
            currentNode = currentNode->getNext();
        }
        else {
            currentNodeFound = true;
        }

        if (i != targetPos && targetNodeFound != true) {
            targetNode = targetNode->getNext();
        }
        else {
            targetNodeFound = true;
        }

        if (currentNodeFound == true && targetNodeFound == true) {
            break;
        }
    }

    remove(currentNode);
    addBetween(currentNode->getElement(), targetNode, targetNode->getNext());
}

void OrdersList::getContents() {
    OrdersList::Node* currentNode = first();
    for (int i = 0; i < getSize(); i++) {
        std::cout << *(currentNode->getElement()) << "\n";
        currentNode = currentNode->getNext();
    }
}