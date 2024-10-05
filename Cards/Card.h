#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Enum to represent the type of cards available in the game
enum CardType {
    BOMB,
    REINFORCEMENT,
    BLOCKADE,
    AIRLIFT,
    DIPLOMACY
};

// Card class representing a single Warzone card
class Card {
public:
    // Constructors
    Card(CardType type);
    Card(const Card& other);

    // Destructor
    ~Card();

    // Assignment operator
    Card& operator=(const Card& other);

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    // Method to play the card
    void play();

    // Get the type of the card
    CardType getType() const;

private:
    CardType* type; // Pointer to CardType to adhere to pointer-type data member rule
};

// Deck class representing a collection of Warzone cards
class Deck {
public:
    // Constructors
    Deck();
    Deck(const Deck& other);

    // Destructor
    ~Deck();

    // Assignment operator
    Deck& operator=(const Deck& other);

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);

    // Method to add a card to the deck
    void addCard(CardType type);

    // Method to draw a card from the deck
    Card* draw();

    // Method to return a card to the deck
    void returnCardToDeck(Card* card);

    // Method to display the deck
    void showDeck() const;

private:
    std::vector<Card*>* cards; // Pointer to a vector of pointers to Cards
};

// Hand class representing a player's collection of cards
class Hand {
public:
    Hand();
    Hand(const Hand& other);
    ~Hand();

    Hand& operator=(const Hand& other);

    friend std::ostream& operator<<(std::ostream& os, const Hand& hand);

    void addCard(Card* card);
    void showHand() const;

    Card* getCard(int index) const;
    int getNumberOfCards() const;
    void removeCard(int index); // Remove card from hand without deleting it

private:
    std::vector<Card*>* handCards;
};