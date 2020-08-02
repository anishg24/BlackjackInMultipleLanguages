#include <stdio.h>
#include "deck.h"
#include "card.h"

Deck generateDeck(){
    Deck deck;
    deck.deckSize = 52;
    int index = 0;
    for(int suit = 0; suit < 4; suit++){
        for(int face = 2; face < 15; face++){
            deck.cards[index] = generateCard((Suit *) suit, (Face *) face);
            index++;
//            printf("(%d, %d)\n", suit, face);
        }
    }
    return deck;
}