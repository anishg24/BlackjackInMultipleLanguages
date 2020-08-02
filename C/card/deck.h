#ifndef DECK_DOT_H
#define DECK_DOT_H
#import "card.h"

typedef struct Deck{
   Card cards[52];
   int deckSize;
} Deck;

Deck generateDeck();

#endif