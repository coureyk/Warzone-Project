#pragma once
#include "Cards.h"

Card::Card(CardType type) {
    this->type = new CardType(type);
    this->isAvailable = new bool(true);  // Initially, the card is available
}

Card::Card(const Card& other) {
    type = new CardType(*other.type);
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
    type = new CardType(*other.type);
    isAvailable = new bool(*other.isAvailable);
    return *this;
}

// Convert the enum to a string for display
std::string Card::getType() const {
    switch (*type) {
    case CardType::Bomb: return "Bomb";
    case CardType::Reinforcement: return "Reinforcement";
    case CardType::Blockade: return "Blockade";
    case CardType::Airlift: return "Airlift";
    case CardType::Diplomacy: return "Diplomacy";
    default: return "Unknown";
    }
}

void Card::play() {
    std::cout << "Playing " << getType() << " card." << std::endl;
    *isAvailable = true;  // Mark card as available again
}

void Card::markTaken() {
    *isAvailable = false;  // Mark card as taken
}
void Card::markAvailable() {
    *isAvailable = true;  // Mark card as available
}
bool Card::isCardAvailable() const {
    return *isAvailable;  // Check if the card is available
}

// Constructor: Initialize the deck with cards of all types
Deck::Deck() {
    cards = new std::vector<Card*>();

    for (int i = 0; i < 2; ++i) {
        cards->push_back(new Card(CardType::Bomb));
        cards->push_back(new Card(CardType::Reinforcement));
        cards->push_back(new Card(CardType::Blockade));
        cards->push_back(new Card(CardType::Airlift));
        cards->push_back(new Card(CardType::Diplomacy));
    }

    std::srand(std::time(0));  // Seed random number generator
}

Deck::~Deck() {
    for (Card* card : *cards) {
        delete card;
    }
    delete cards;
}

Card* Deck::draw() {
    // Create a vector to store all available cards
    std::vector<Card*> availableCards;

    // Loop through the deck and gather all available cards
    for (Card* card : *cards) {
        if (card->isCardAvailable()) {
            availableCards.push_back(card);
        }
    }

    // Check if there is any available cards
    if (availableCards.empty()) {
        std::cout << "No available cards to draw!" << std::endl;
        return nullptr;
    }

    // Randomly pick an available card
    int randomIndex = std::rand() % availableCards.size();
    Card* chosenCard = availableCards[randomIndex];

    // Mark the chosen card as taken
    chosenCard->markTaken();
    std::cout << "Drew a " << chosenCard->getType() << " card." << std::endl;

    return chosenCard;
}



void Deck::returnCard(Card* card) {
    card->markAvailable();
    std::cout << "Returned " << card->getType() << " card to the deck." << std::endl;
}

void Deck::showDeck() const {
    std::cout << "Deck contains the following cards:" << std::endl;
    for (Card* card : *cards) {
        std::cout << "- " << card->getType()
            << " (Status: " << (card->isCardAvailable() ? "Available" : "Taken") << ")"
            << std::endl;
    }
}
// Constructor: Initialize the hands and create a vector to store all cards drawing from Deck
Hand::Hand() {
    handCards = new std::vector<Card*>();
}

Hand::~Hand() {
    delete handCards;
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
int Hand::getCardCount() const {
    return handCards->size();
}
