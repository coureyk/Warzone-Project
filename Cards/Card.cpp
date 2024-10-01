#include "Card.h"

// Card class implementation
Card::Card(CardType type) {
    this->type = new CardType(type);
}

Card::Card(const Card& other) {
    this->type = new CardType(*other.type);
}

Card::~Card() {
    delete type;
}

Card& Card::operator=(const Card& other) {
    if (this == &other) {
        return *this;
    }
    delete this->type;
    this->type = new CardType(*other.type);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const char* cardNames[] = { "Bomb", "Reinforcement", "Blockade", "Airlift", "Diplomacy" };
    os << cardNames[*card.type];
    return os;
}

void Card::play() {
    std::string order;
    switch (*type) {
    case Bomb:
        order = "Bomb Order Created";
        break;
    case Reinforcement:
        order = "Reinforcement Order Created";
        break;
    case Blockade:
        order = "Blockade Order Created";
        break;
    case Airlift:
        order = "Airlift Order Created";
        break;
    case Diplomacy:
        order = "Diplomacy Order Created";
        break;
    }
    std::cout << order << std::endl;
}

// Deck class implementation
Deck::Deck() {
    cards = new std::vector<Card*>();
    std::srand(std::time(0));
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
    if (this == &other) {
        return *this;
    }
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

std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    os << "Deck with " << deck.cards->size() << " cards.";
    return os;
}

void Deck::addCard(CardType type) {
    cards->push_back(new Card(type));
}

Card* Deck::draw() {
    if (cards->empty()) {
        throw std::out_of_range("No more cards in the deck.");
    }
    int index = std::rand() % cards->size();
    Card* drawnCard = cards->at(index);
    cards->erase(cards->begin() + index);
    return drawnCard;
}

void Deck::returnCardToDeck(Card* card) {
    cards->push_back(card);
}

void Deck::showDeck() const {
    std::cout << "Deck contains " << cards->size() << " cards." << std::endl;
}

// Hand class implementation
Hand::Hand() {
    handCards = new std::vector<Card*>();
}

Hand::Hand(const Hand& other) {
    handCards = new std::vector<Card*>();
    for (Card* card : *other.handCards) {
        handCards->push_back(new Card(*card));
    }
}

Hand::~Hand() {
    for (Card* card : *handCards) {
        delete card;
    }
    delete handCards;
}

Hand& Hand::operator=(const Hand& other) {
    if (this == &other) {
        return *this;
    }
    for (Card* card : *handCards) {
        delete card;
    }
    delete handCards;
    handCards = new std::vector<Card*>();
    for (Card* card : *other.handCards) {
        handCards->push_back(new Card(*card));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Hand& hand) {
    os << "Hand with " << hand.handCards->size() << " cards.";
    return os;
}

void Hand::addCard(Card* card) {
    handCards->push_back(card);
}

Card* Hand::getCard(int index) const {
    if (index < 0 || index >= handCards->size()) {
        throw std::out_of_range("Invalid card index.");
    }
    return handCards->at(index);
}

int Hand::getNumberOfCards() const {
    return handCards->size();
}

void Hand::removeCard(int index) {
    if (index < 0 || index >= handCards->size()) {
        throw std::out_of_range("Invalid card index.");
    }
    handCards->erase(handCards->begin() + index); // Remove the card without deleting it
}


void Hand::showHand() const {
    std::cout << "Hand contains " << handCards->size() << " cards." << std::endl;
}
