#include "Cards.h"
void testCards() {
    // Create a deck of Warzone cards
    Deck deck;
    deck.addCard(Bomb);
    deck.addCard(Reinforcement);
    deck.addCard(Blockade);
    deck.addCard(Airlift);
    deck.addCard(Diplomacy);

    // Show initial deck
    std::cout << deck << std::endl;

    // Create a hand object
    Hand hand;

    // Draw all cards from the deck to fill the hand
    for (int i = 0; i < 5; ++i) {
        Card* drawnCard = deck.draw();
        hand.addCard(drawnCard);
    }

    // Show hand after drawing cards
    std::cout << hand << std::endl;

    // Play all cards in the hand one by one
    while (hand.getNumberOfCards() > 0) {
        Card* card = hand.getCard(0); // Get the first card
        card->play();
        deck.returnCardToDeck(card); // Return the card to the deck
        hand.removeCard(0);          // Remove the card from the hand (this should not delete the card)
    }

    // Show final deck after all cards have been returned
    std::cout << deck << std::endl;
}
