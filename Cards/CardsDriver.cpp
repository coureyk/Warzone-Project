#include "Cards.h"

void testCards() {
    Deck deck;
    deck.showDeck();
    Hand hand;

    // Drawing cards from the deck
    for (int i = 0; i < 5; ++i) {
        Card* drawnCard = deck.draw();
        if (drawnCard != nullptr) {
            hand.addCard(drawnCard);
        }
    }
    deck.showDeck();
    hand.showHand();
    // Playing cards in the hand
    while (hand.getCardCount() > 0) {
        hand.playCard(0);  // Play the first card in the hand
    }
    deck.showDeck();
    hand.showHand();
}
