#ifndef PLAYER_DOT_H
#define PLAYER_DOT_H
#include "../card/deck.h"
#include "../card/card.h"

typedef struct Player {
    char name[50];
    Card hand[10];
    int isDealer;
    int lastIndex;
    int score;
} Player;

Player generatePlayer(Deck *deck, int isDealer);

void printHand(Player *player);

void draw(Player *player, Deck *deck, int num);

void removeCardFromDeck(Deck *deck, int index);

#endif