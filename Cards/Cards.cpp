#include "Cards.h"

Card::Card(std::string type) {
    this->type = new std::string(type);
    this->isAvailable = new bool(true);  // Initially, the card is available
}

Card::Card(const Card& other) {
    type = new std::string(*other.type);
    isAvailable = new bool(*other.isAvailable);
}

Card::~Card() {
    delete type;
    delete isAvailable;
}

Card& Card::operator=(const Card& other) {
    if (this == &other) return *this;
    delete type;
    delete isAvailable;
    type = new std::string(*other.type);
    isAvailable = new bool(*other.isAvailable);
    return *this;
}

std::string Card::getType() const {
    return *type;
}

void Card::play() {
    std::cout << "Playing " << *type << " card." << std::endl;
    *isAvailable = true;  // Mark card as available again
}

void Card::markTaken() {
    *isAvailable = false;  // Mark card as taken
}

void Card::markAvailable() {
    *isAvailable = true;
}

bool Card::isCardAvailable() const {
    return *isAvailable;
}

Deck::Deck() {
    cards = new std::vector<Card*>();
    std::string types[] = { "bomb", "reinforcement", "blockade", "airlift", "diplomacy" };
    for (const std::string& type : types) {
        cards->push_back(new Card(type));
    }
    std::srand(std::time(0));  // Seed random number generator
}

Deck::Deck(const Deck& other) {
    cards = new std::vector<Card*>();
    for (Card* card : *other.cards) {
        cards->push_back(new Card(*card));
    }
}

Deck::~Deck() {
    for (Card* card : *cards) {
        delete card;
    }
    delete cards;
}

Deck& Deck::operator=(const Deck& other) {
    if (this == &other) return *this;
    for (Card* card : *cards) {
        delete card;
    }
    delete cards;

    cards = new std::vector<Card*>();
    for (Card* card : *other.cards) {
        cards->push_back(new Card(*card));
    }
    return *this;
}
void Deck::showDeck() const {
    std::cout << "Deck contains the following cards:" << std::endl;
    for (Card* card : *cards) {
        std::cout << "- " << card->getType()
            << " (Status: " << (card->isCardAvailable() ? "Available" : "Taken") << ")"
            << std::endl;
    }
}

Card* Deck::draw() {
    for (Card* card : *cards) {
        if (card->isCardAvailable()) {
            card->markTaken();
            std::cout << "Drew a " << card->getType() << " card." << std::endl;
            return card;
        }
    }
    std::cout << "No available cards to draw!" << std::endl;
    return nullptr;
}

void Deck::returnCard(Card* card) {
    card->markAvailable();
    std::cout << "Returned " << card->getType() << " card to the deck." << std::endl;
}
Hand::Hand() {
    handCards = new std::vector<Card*>();
}

Hand::Hand(const Hand& other) {
    handCards = new std::vector<Card*>();
    for (Card* card : *other.handCards) {
        handCards->push_back(card);
    }
}

Hand::~Hand() {
    delete handCards;
}

Hand& Hand::operator=(const Hand& other) {
    if (this == &other) return *this;
    delete handCards;
    handCards = new std::vector<Card*>();
    for (Card* card : *other.handCards) {
        handCards->push_back(card);
    }
    return *this;
}
void Hand::showHand() const {
    std::cout << "Hand contains the following cards:" << std::endl;
    if (handCards->empty()) {
        std::cout << "Hand is empty!" << std::endl;
    }
    else {
        for (Card* card : *handCards) {
            std::cout << "- " << card->getType() << std::endl;
        }
    }
}

void Hand::addCard(Card* card) {
    handCards->push_back(card);
    std::cout << "Added " << card->getType() << " card to hand." << std::endl;
}

void Hand::playCard(int index) {
    if (index >= 0 && index < handCards->size()) {
        Card* card = (*handCards)[index];
        if (card != nullptr) {
            card->play();  // Use the Card class's play method
            handCards->erase(handCards->begin() + index);  // Remove card from hand
        }
    }
}

int Hand::getCardCount() const {
    return handCards->size();
}