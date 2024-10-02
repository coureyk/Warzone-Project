#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Card {
private:
    std::string* type;  // Pointer to the type of card
    bool* isAvailable;  // Pointer to availability status (true: available, false: taken)

public:
    Card(std::string type);
    Card(const Card& other);  // Copy constructor
    ~Card();  // Destructor
    Card& operator=(const Card& other);  // Assignment operator

    std::string getType() const;
    void play();  // Play the card and mark as available
    void markTaken();  // Mark card as taken
    void markAvailable();  // Mark card as available
    bool isCardAvailable() const;  // Check if the card is available
};

class Deck {
private:
    std::vector<Card*>* cards;  // Pointer to a collection of cards

public:
    Deck();
    Deck(const Deck& other);  // Copy constructor
    ~Deck();  // Destructor
    Deck& operator=(const Deck& other);  // Assignment operator
    void showDeck() const;
    Card* draw();  // Draw a card from the deck
    void returnCard(Card* card);  // Return a played card to the deck
};

class Hand {
private:
    std::vector<Card*>* handCards;  // Pointers to cards in deck

public:
    Hand();
    Hand(const Hand& other);  // Copy constructor
    ~Hand();  // Destructor
    Hand& operator=(const Hand& other);  // Assignment operator
    void showHand() const;
    void addCard(Card* card);  // Add a card pointer to the hand
    void playCard(int index);  // Call play on a specific card from the hand
    int getCardCount() const;  // Get the number of cards in hand
};

#endif
